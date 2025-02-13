#include "proj3/kernel/xv6timer.h"
#include "kernel/types.h"
#include "kernel/proc.h"  // Ensure full struct proc definition
#include "kernel/defs.h"  
#include "kernel/spinlock.h"  

extern uint ticks;

void xv6timer_init(struct xv6timer_t *ptimer, struct proc *proc) {
    ptimer->expiry = 0;
    ptimer->next_tick = 0;
    ptimer->proc = proc;
    ptimer->callback = 0;
}

void xv6timer_forward(struct xv6timer_t *ptimer, int expiry) {
    ptimer->expiry = expiry;
    ptimer->next_tick = ticks + expiry; 
}

void xv6timer_register_callback(struct xv6timer_t *ptimer, void (*callback)(struct xv6timer_t *)) {
    ptimer->callback = callback;
}

void xv6timer_interrupt(struct xv6timer_t *ptimer) {
    if (ptimer->callback && ticks >= ptimer->next_tick) {
        printf("[DEBUG] Timer interrupt for process %d\n", ptimer->proc->pid);
        
        ptimer->callback(ptimer);  // ✅ Wake up the sleeping process
        ptimer->next_tick = ticks + ptimer->expiry;  // Reschedule the timer

        printf("[DEBUG] Process %d timer rescheduled to tick %d\n", ptimer->proc->pid, ptimer->next_tick);
    }
}
