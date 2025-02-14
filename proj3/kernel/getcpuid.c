#include "../../kernel/types.h"
#include "../../kernel/param.h"    
#include "../../kernel/memlayout.h" 
#include "../../kernel/riscv.h"     
#include "../../kernel/spinlock.h" 
#include "../../kernel/proc.h"      
#include "../../kernel/defs.h"      

uint64 sys_getcpuid(void) {
    return cpuid();  
}
