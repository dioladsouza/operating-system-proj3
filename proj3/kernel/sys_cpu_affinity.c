#include "../../kernel/types.h"
#include "../../kernel/fs.h"
#include "../../kernel/param.h"
#include "../../kernel/memlayout.h"
#include "../../kernel/riscv.h"
#include "../../kernel/defs.h"
#include "../../kernel/spinlock.h"
#include "../../kernel/proc.h"
#include "../../kernel/syscall.h"
#include "../../kernel/sleeplock.h"
#include "../../kernel/file.h"
#include "../../kernel/fcntl.h"

int sys_set_cpu_affinity(void) {
    int cpu_mask;
    argint(0, &cpu_mask);
    if (cpu_mask < 0 || cpu_mask >= (1<< NCPU)) 
        return -1; 

    struct proc *current_proc = myproc();
    current_proc->cpu_mask = cpu_mask; 

    return 0;
}