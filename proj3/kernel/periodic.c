#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"
#include "kernel/spinlock.h"
#include "kernel/proc.h"
#include "kernel/defs.h"
#include "proj3/kernel/xv6timer.h"

void timer_wakeup(struct xv6timer_t *timer) {
    printf("[DEBUG] Waking up process %d\n", timer->proc->pid);
    wakeup(timer->proc);  // ✅ Wake up the process
}

uint64 sys_setperiod(void) {
    int period;
    argint(0, &period);  // Fetch system call argument

    if (period < 1)  // Validate period after assignment
        return -1;

    struct proc *p = myproc();

    // Initialize and configure the process timer
    printf("[DEBUG] Initializing timer for process %d with period %d\n", p->pid, period);
    xv6timer_init(&p->timer, p);
    xv6timer_forward(&p->timer, period);
    xv6timer_register_callback(&p->timer, timer_wakeup);

    return 0;
}

uint64 sys_wait_until_next_period(void) {
    struct proc *p = myproc();
    // printf("[DEBUG] Process %d waiting for next period\n", p->pid);

    acquire(&p->lock);  
    // printf("[DEBUG] Process %d acquired lock\n", p->pid);

    // printf("[DEBUG] Process %d going to sleep\n", p->pid);
    sleep(&p->timer, &p->lock);  // ✅ sleep releases p->lock internally

    // After sleep is called, the process is supposed to wake up when `wakeup` is triggered
    // printf("[DEBUG] Process %d woke up\n", p->pid);

    release(&p->lock);  
    // printf("[DEBUG] Process %d released lock\n", p->pid);

    return 0;
}
