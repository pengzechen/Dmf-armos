
#include <aj_types.h>
#include <sys/sys.h>

void hyp_reg_write(uint8_t reg_id, uint64_t value, uint64_t *sp){
    if(0 <= reg_id && reg_id <= 7){
        sp[(uint64_t)reg_id] = value;
    } else if(8 <= reg_id && reg_id <= 12) {
        uint64_t spsr;
        __asm__ __volatile__("mrs %0, spsr":"=r"(spsr));
        spsr &= 0x1f;
        if(spsr==PSM_FIQ){
            switch(reg_id){
                case 8:
                    __asm__ __volatile__("msr r8_fiq, %0":"=r"(value));
                    break;
                case 9:
                    __asm__ __volatile__("msr r9_fiq, %0":"=r"(value));
                    break;
                case 10:
                    __asm__ __volatile__("msr r10_fiq, %0":"=r"(value));
                    break;
                case 11:
                    __asm__ __volatile__("msr r11_fiq, %0":"=r"(value));
                    break;
                default:
                    __asm__ __volatile__("msr r12_fiq, %0":"=r"(value));
                    break;
            }
        } else {
            sp[(uint64_t)reg_id] = value;
        }
    } else if(reg_id==14) {
        uint64_t spsr;
        __asm__ __volatile__("mrs %0, spsr":"=r"(spsr));
        spsr &= 0x1f;
        switch(spsr){
            case PSM_USR:
                sp[13] = value;
                break;
            case PSM_FIQ:
                __asm__ __volatile__("msr lr_fiq, %0"::"r"(value));
                break;
            case PSM_IRQ:
                __asm__ __volatile__("msr lr_irq, %0"::"r"(value));
                break;
            case PSM_SVC:
                __asm__ __volatile__("msr lr_svc, %0"::"r"(value));
                break;
            case PSM_ABT:
                __asm__ __volatile__("msr lr_abt, %0"::"r"(value));
                break;
            case PSM_UND:
                __asm__ __volatile__("msr lr_und, %0"::"r"(value));
                break;
            case PSM_SYS:
                sp[13] = value;
                break;
            default:
                tv_abort("!!! unknown !!!\n");
                break;

        }
    } else if(reg_id==13) {
        uint64_t spsr;
        __asm__ __volatile__("mrs %0, spsr":"=r"(spsr));
        spsr &= 0x1f;
        switch(spsr){
            case PSM_USR:
                __asm__ __volatile__("msr sp_usr, %0"::"r"(value));
                break;
            case PSM_FIQ:
                __asm__ __volatile__("msr sp_fiq, %0"::"r"(value));
                break;
            case PSM_IRQ:
                __asm__ __volatile__("msr sp_irq, %0"::"r"(value));
                break;
            case PSM_SVC:
                __asm__ __volatile__("msr sp_svc, %0"::"r"(value));
                break;
            case PSM_ABT:
                __asm__ __volatile__("msr sp_abt, %0"::"r"(value));
                break;
            case PSM_UND:
                __asm__ __volatile__("msr sp_und, %0"::"r"(value));
                break;
            case PSM_SYS:
                __asm__ __volatile__("msr sp_usr, %0"::"r"(value));
                break;
            default:
                tv_abort("!!! unknown !!!\n");
                break;

        }
    } else if(reg_id==15) {
        __asm__ __volatile__("msr elr_hyp, %0"::"r"(value));
    } else {
        tv_abort("!!! unknown !!!\n");
    }
}

uint64_t hyp_reg_read(uint8_t reg_id, uint64_t *sp){
    if(0 <= reg_id && reg_id <= 7){
        return sp[(uint64_t)reg_id];
    } else if(8 <= reg_id && reg_id <= 12) {
        uint64_t spsr;
        __asm__ __volatile__("mrs %0, spsr":"=r"(spsr));
        spsr &= 0x1f;
        uint64_t value;
        if(spsr==PSM_FIQ){
            switch(reg_id){
                case 8:
                    __asm__ __volatile__("mrs %0, r8_fiq":"=r"(value));
                    break;
                case 9:
                    __asm__ __volatile__("mrs %0, r9_fiq":"=r"(value));
                    break;
                case 10:
                    __asm__ __volatile__("mrs %0, r10_fiq":"=r"(value));
                    break;
                case 11:
                    __asm__ __volatile__("mrs %0, r11_fiq":"=r"(value));
                    break;
                default:
                    __asm__ __volatile__("mrs %0, r12_fiq":"=r"(value));
                    break;
            }
            return value;
        } else {
            return sp[(uint64_t)reg_id];
        }
    } else if(reg_id==14) {
        uint64_t spsr;
        __asm__ __volatile__("mrs %0, spsr":"=r"(spsr));
        spsr &= 0x1f;
        uint64_t value;
        switch(spsr){
            case PSM_USR:
                value = sp[13];
                break;
            case PSM_FIQ:
                __asm__ __volatile__("mrs %0, lr_fiq":"=r"(value));
                break;
            case PSM_IRQ:
                __asm__ __volatile__("mrs %0, lr_irq":"=r"(value));
                break;
            case PSM_SVC:
                __asm__ __volatile__("mrs %0, lr_svc":"=r"(value));
                break;
            case PSM_ABT:
                __asm__ __volatile__("mrs %0, lr_abt":"=r"(value));
                break;
            case PSM_UND:
                __asm__ __volatile__("mrs %0, lr_und":"=r"(value));
                break;
            case PSM_SYS:
                value = sp[13];
                break;
            default:
                value = 0;
                tv_puts("!!! unknown !!!\n");
                break;

        }
        return value;
    } else if(reg_id==13) {
        uint64_t spsr;
        __asm__ __volatile__("mrs %0, spsr":"=r"(spsr));
        spsr &= 0x1f;
        uint64_t value = 0;
        switch(spsr){
            case PSM_USR:
                __asm__ __volatile__("mrs %0, sp_usr":"=r"(value));
                break;
            case PSM_FIQ:
                __asm__ __volatile__("mrs %0, sp_fiq":"=r"(value));
                break;
            case PSM_IRQ:
                __asm__ __volatile__("mrs %0, sp_irq":"=r"(value));
                break;
            case PSM_SVC:
                __asm__ __volatile__("mrs %0, sp_svc":"=r"(value));
                break;
            case PSM_ABT:
                __asm__ __volatile__("mrs %0, sp_abt":"=r"(value));
                break;
            case PSM_UND:
                __asm__ __volatile__("mrs %0, sp_und":"=r"(value));
                break;
            case PSM_SYS:
                __asm__ __volatile__("mrs %0, sp_usr":"=r"(value));
                break;
            default:
                tv_puts("!!! unknown !!!\n");
                break;

        }
        return value;
    } else if(reg_id==15) {
        uint64_t value;
        __asm__ __volatile__("mrs %0, elr_hyp":"=r"(value));
        return value;
    } 
    tv_puts("!!! unknown !!!\n");
    return 0;
}

void hyp_memory_passthrough(uint64_t iss, uint64_t *addr, uint64_t *sp){
    // read or write
    bool is_write = (iss&(1 << 6)) > 0;
    // reg_id
    uint8_t reg_id = (iss&0xf0000) >> 16;
    // length
    uint8_t len = (iss&0xc00000) >> 22;
    // signed
    bool sse = (iss&(1 << 21)) > 0;

    if(is_write){
        uint64_t value = hyp_reg_read(reg_id, sp);
        switch(len){
            case 0x0:
                OUTB(addr,value&0xff);
                break;
            case 0x1:
                OUTHW(addr,value&0xffff);
                break;
            case 0x2:
                OUTW(addr,value);
                break;
            default:
                tv_puts("!!! unknown length !!!\n");
                break;
        }
    } else {
        if(sse){
            int32_t value;
            switch(len){
                case 0x0:
                    value = INB(addr);
                    break;
                case 0x1:
                    value = INHW(addr);
                    break;
                case 0x2:
                    value = INW(addr);
                    break;
                default:
                    tv_puts("!!! unknown length !!!\n");
                    value = 0;
                    break;
            }
            hyp_reg_write(reg_id,value,sp);
        } else {
            uint64_t value;
            switch(len){
                case 0x0:
                    value = (uint8_t)INB(addr);
                    break;
                case 0x1:
                    value = (uint16_t)INHW(addr);
                    break;
                case 0x2:
                    value = (uint64_t)INW(addr);
                    break;
                default:
                    tv_puts("!!! unknown length !!!\n");
                    value = 0;
                    break;
            }
            hyp_reg_write(reg_id,value,sp);
        }
    }
}
