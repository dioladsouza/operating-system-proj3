#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"
#include "kernel/spinlock.h"
#include "kernel/proc.h"
#include "kernel/defs.h"
#include "proj3/kernel/xv6timer.h"

#define MAX_PERIODIC_TASKS 4

static int periodic_task_count = 0;  // Track the number of periodic tasks

uint64 sys_getticks(void) {
    return ticks;  // Simply return the current tick value
}

void timer_wakeup(struct xv6timer_t *timer) {
    // printf("[DEBUG] Waking up process %d\n", timer->proc->pid);
    wakeup(timer->proc);  // Wake up the process
    // Decrement the periodic task counter after waking up
    periodic_task_count--;
    // printf("[DEBUG] Periodic task finished for process %d. Current count: %d\n", timer->proc->pid, periodic_task_count);
}

uint64 sys_setperiod(void) {
    int period;
    argint(0, &period);  // Fetch system call argument

    if (period < 1)  // Validate period after assignment
        return -1;

    struct proc *p = myproc();

    // Check if there are already 4 periodic tasks
    if (periodic_task_count >= MAX_PERIODIC_TASKS) {
        // Reject the request if the limit is reached
        printf("[DEBUG] Too many periodic tasks. Task limit reached.\n");
        return -1;
    }

    // Initialize and configure the process timer
    printf("\n[DEBUG] Initializing timer for process %d with period %d\n", p->pid, period);
    xv6timer_init(&p->timer, p);
    xv6timer_forward(&p->timer, period);
    xv6timer_register_callback(&p->timer, timer_wakeup);

    // Increment the periodic task counter
    periodic_task_count++;
    printf("[DEBUG] Process %d added to periodic tasks. Current count: %d\n", p->pid, periodic_task_count);

    return 0;
}

uint64 sys_wait_until_next_period(void) {
    struct proc *p = myproc();

    acquire(&p->lock);  
    sleep(&p->timer, &p->lock);  // sleep releases p->lock internally
    release(&p->lock);  

    return 0;
}
