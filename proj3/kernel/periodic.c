#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"
#include "kernel/spinlock.h"
#include "kernel/proc.h"
#include "kernel/defs.h"
#include "proj3/kernel/xv6timer.h"

#define MAX_PERIODIC_TASKS 4

static int periodic_task_count = 0;  

uint64 sys_getticks(void) {
    return ticks;  
}

void timer_wakeup(struct xv6timer_t *timer) {
    wakeup(timer->proc);  
    periodic_task_count--;
}

uint64 sys_setperiod(void) {
    int period;
    argint(0, &period);  

    if (period < 1)  
        return -1;

    struct proc *p = myproc();

    if (periodic_task_count >= MAX_PERIODIC_TASKS) {
        printf("[DEBUG] Too many periodic tasks. Task limit reached.\n");
        return -1;
    }

    printf("\n[DEBUG] Initializing timer for process %d with period %d\n", p->pid, period);
    xv6timer_init(&p->timer, p);
    xv6timer_forward(&p->timer, period);
    xv6timer_register_callback(&p->timer, timer_wakeup);

    periodic_task_count++;
    printf("[DEBUG] Process %d added to periodic tasks. Current count: %d\n", p->pid, periodic_task_count);

    return 0;
}

uint64 sys_wait_until_next_period(void) {
    struct proc *p = myproc();

    acquire(&p->lock);  
    sleep(&p->timer, &p->lock);  
    release(&p->lock);  

    return 0;
}
