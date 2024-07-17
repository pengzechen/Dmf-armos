

#ifndef __VGIC_H__
#define __VGIC_H__

#include <aj_types.h>
#include "vm.h"
#include "gic.h"

typedef struct {
    uint32_t id;
    uint32_t vmcr;    //GIC state;
    uint32_t pending_lr[SPI_ID_MAX];
    uint32_t saved_lr[GICH_LR_NUM]; 
    uint32_t saved_elsr0;
    uint32_t saved_apr;
    uint32_t saved_hcr;
    uint32_t irq_no_mask[SPI_ID_MAX/32];  // pendingなirqを記録する

    uint32_t ppi_isenabler;
    uint8_t ppi_ipriorityr[GIC_FIRST_SPI];
} vgic_core_state_t;

typedef struct _vgic_t {
    vm_t *vm;
    
    uint32_t ptov[SPI_ID_MAX];           // 実irq idを仮想irq idに
    uint32_t vtop[SPI_ID_MAX];
    uint32_t use_irq[SPI_ID_MAX/32];     // このgicが利用する実irq id
    uint32_t real_pri;

    vgic_core_state_t *core_state;

    bool enable_g0;
    bool enable_g1;
    uint32_t gicd_typer;
    uint32_t gicd_iidr;
    uint32_t gicd_igroupr[SPI_ID_MAX/32];
    uint32_t gicd_isenabler[SPI_ID_MAX/32];
    
    uint8_t gicd_ipriorityr[SPI_ID_MAX];
    uint8_t gicd_itargetsr[SPI_ID_MAX];
    
    uint32_t gicd_icfgr[SPI_ID_MAX/16];
    uint32_t gicd_nsacr[SPI_ID_MAX/16];
} vgic_t ;


#endif // __VGIC_H__