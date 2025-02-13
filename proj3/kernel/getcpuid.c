#include "../../kernel/types.h"
#include "../../kernel/param.h"     // Defines NCPU
#include "../../kernel/memlayout.h" // Required for memory layout definitions
#include "../../kernel/riscv.h"     // For cpuid() function
#include "../../kernel/spinlock.h"  // Required for struct spinlock
#include "../../kernel/proc.h"      // Process management functions
#include "../../kernel/defs.h"      // Function declarations

uint64 sys_getcpuid(void) {
    return cpuid();  // Use existing cpuid() function
}
