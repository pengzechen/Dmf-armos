
#include <page.h>
#include <ept.h>
#include <os_cfg.h>
#include <page.h>
#include <io.h>

#define LPAE_SHIFT 9
#define LPAE_ENTRIES (1 << LPAE_SHIFT)
#define LPAE_L1_SIZE (8)
#define LPAE_L2_SIZE (LPAE_L1_SIZE * LPAE_ENTRIES)
#define LPAE_L3_SIZE (LPAE_L2_SIZE * LPAE_ENTRIES)

extern lpae_t ept_L1[];
lpae_t *ept_L2_root;
lpae_t *ept_L3_root;

/* Return the cache property of the input gpa */
/* It is determined depending on whether the address is for device or memory */
static bool isInMemory(unsigned long gpa)
{
  if (RAM_START <= gpa && gpa < RAM_END)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void ept_l3_init(lpae_t *ept_l3)
{
  unsigned long long gpa = 0;

  for (int index_l3 = 0; index_l3 < LPAE_ENTRIES; index_l3++)
  {
    lpae_t entry_l3;
    /* Set third level page table entries */
    /* 4KB Page */
    entry_l3.bits = 0;
    entry_l3.p2m.valid = 1;
    entry_l3.p2m.table = 1;
    entry_l3.p2m.af = 1;
    entry_l3.p2m.read = 1;
    entry_l3.p2m.write = 1;
    entry_l3.p2m.mattr = 0xF;
    entry_l3.p2m.sh = 0x03;
    entry_l3.p2m.xn = 0x0;

    if (isInMemory(gpa))
    {
      /* RAM area */
      entry_l3.p2m.sh = 0x03;
      entry_l3.p2m.mattr = 0xF; /* 1111b: Outer Write-back Cacheable / Inner write-back cacheable */
    }
    else
    {
      /* Device area */
      entry_l3.p2m.mattr = 0x1; /* 0001b: Device Memory */
      entry_l3.p2m.sh = 0x0;
      entry_l3.p2m.xn = 1;
    }
    entry_l3.bits |= gpa;
    ept_l3[index_l3].bits = entry_l3.bits;
    // {
    //   /* For logging.. */
    //   lpae_t *pept;
    //   pept = get_ept_entry(gpa);
    //   if(pept != &ept_l3[index_l3])
    //   {
    //     printf("(Index)%d/%d/%d - ", index_l1,index_l2,index_l3);
    //     printf("(L1)0x%x - ",(unsigned long)entry_l1.bits);
    //     printf("(L2Adr)0x%x - ",(unsigned long)&ept_l2[index_l2]);
    //     printf("(L2)0x%x - ",(unsigned long)entry_l2.bits);
    //     printf("(L3Adr)0x%x - ",(unsigned long)&ept_l3[index_l3]);
    //     printf("(L3)0x%x - ",(unsigned long)entry_l3.bits);
    //     printf("(GPA)0x%x - ",(unsigned long)gpa);
    //     printf("Error - ");
    //     printf("(EPT)0x%x - ",ept_l3);
    //     printf("(PAddr)0x%x - (PVAL)0x%x\n",pept,(unsigned long)pept->bits);
    //   }
    // }
    gpa += (4 * 1024); /* 4KB page frame */
  }
  apply_ept(ept_l3);
}

void ept_l2_init(lpae_t *ept_l2, int index_l1)
{
  for (int index_l2 = 0; index_l2 < LPAE_ENTRIES; index_l2++)
  {
    lpae_t entry_l2;
    lpae_t *ept_l3 = &ept_L3_root[LPAE_ENTRIES * LPAE_ENTRIES * index_l1 + LPAE_ENTRIES * index_l2];
    // printf("(EPT_L3)0x%x - %d/%d (%d)\n",ept_l3, index_l1,index_l2, LPAE_L2_SIZE * LPAE_ENTRIES * index_l1  + LPAE_ENTRIES * index_l2);

    /* Set second level page table entries */
    entry_l2.bits = 0;
    entry_l2.p2m.valid = 1;
    entry_l2.p2m.table = 1;
    entry_l2.bits |= (unsigned long)ept_l3;
    ept_l2[index_l2].bits = entry_l2.bits;

    ept_l3_init(ept_l3);
  }
  apply_ept(ept_l2);
}

void ept_l1_init()
{
  for (int index_l1 = 0; index_l1 < LPAE_L1_SIZE; index_l1++)
  {
    lpae_t entry_l1;
    lpae_t *ept_l2 = &ept_L2_root[LPAE_ENTRIES * index_l1];

    /* Set first level page table entries */
    entry_l1.bits = 0;
    entry_l1.p2m.valid = 1;
    entry_l1.p2m.table = 1;
    entry_l1.bits |= (unsigned long)ept_l2;

    ept_L1[index_l1].bits = entry_l1.bits;
    ept_l2_init(ept_l2, index_l1);
  }
  apply_ept(ept_L1);
}

void guest_ept_init(void)
{
  int index_l1, index_l2, index_l3;

  unsigned long vttbr_val = (unsigned long)ept_L1;
  unsigned long hcr;

  /* Calculate next level page table address */

  /* Level 2 */
  ept_L2_root = &ept_L1[LPAE_L1_SIZE];
  ept_L2_root = (lpae_t *)(((unsigned long)ept_L2_root + (1 << 12)) & ~0xFFF); /* Align */
  /* Level 3 */
  ept_L3_root = &ept_L2_root[LPAE_L2_SIZE];

  print_info("    Initialize EPT...\n");
  printf("EPT root address : 0x%x\n", ept_L1);
  printf("ept_L2_root : 0x%x\n", ept_L2_root);
  printf("ept_L3_root : 0x%x\n", ept_L3_root);
  printf("LPAE_L1_SIZE : %d\n", LPAE_L1_SIZE); // 8
  printf("LPAE_L2_SIZE : %d\n", LPAE_L2_SIZE); // 8 * 512
  printf("LPAE_L3_SIZE : %d\n", LPAE_L3_SIZE); // 8 * 512 * 512

  ept_l1_init();

  // dsb();
  // isb();
  // init_mmio();
  // dsb();
  // isb();
  asm volatile(
      "msr VTTBR_EL2 , %0\n\t"
      : /* no out put */
      : "r"(vttbr_val)
      :);
  // Turn on Stage 2 Address Translation
  // hcr = READ_SYSREG(HCR_EL2);
  // WRITE_SYSREG(hcr | HCR_PTW | HCR_VM, HCR_EL2);
  isb();
}