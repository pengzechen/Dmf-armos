
#include <aj_types.h>

struct spinlock {
	int v;
};

void spin_lock(struct spinlock *lock)
{
	uint32_t val, fail;

	if (!mmu_enabled()) {
		lock->v = 1;
		smp_mb();
		return;
	}

	do {
		asm volatile(
		"1:	ldaxr	%w0, [%2]\n"
		"	cbnz	%w0, 1b\n"
		"	mov	%0, #1\n"
		"	stxr	%w1, %w0, [%2]\n"
		: "=&r" (val), "=&r" (fail)
		: "r" (&lock->v)
		: "cc" );
	} while (fail);
	smp_mb();
}

void spin_unlock(struct spinlock *lock)
{
	smp_mb();
	if (!mmu_enabled())
		lock->v = 0;
	else
		asm volatile("stlrh wzr, [%0]" :: "r" (&lock->v));
}
