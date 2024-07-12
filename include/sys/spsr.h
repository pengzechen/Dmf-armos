

#ifndef __SPSR_H__
#define __SPSR_H__

#define PSR_FIQ_MASK    (1<<6)        /* Fast Interrupt mask */
#define PSR_IRQ_MASK    (1<<7)        /* Interrupt mask */
#define PSR_ABT_MASK    (1<<8)        /* Asynchronous Abort mask */

#define SPSR_INIT (PSR_FIQ_MASK | PSR_IRQ_MASK | PSR_ABT_MASK)

#endif // __SPSR_H__