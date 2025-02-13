#ifndef XV6TIMER_H
#define XV6TIMER_H

#include "kernel/types.h"  // Ensure basic types like uint are available
// #include "kernel/proc.h"   // Ensure full struct proc definition before use

struct proc;  // ✅ Forward declaration to avoid including proc.h

struct xv6timer_t;  // Forward declaration (optional but safe)

typedef void (*xv6timer_callback_t)(struct xv6timer_t *);

struct xv6timer_t {
    int expiry;             // Number of ticks between interrupts
    uint next_tick;         // Tick count when the timer should trigger next
    struct proc *proc;      // Associated process
    xv6timer_callback_t callback; // Callback function
};

void xv6timer_init(struct xv6timer_t *ptimer, struct proc *proc);
void xv6timer_forward(struct xv6timer_t *ptimer, int expiry);
void xv6timer_register_callback(struct xv6timer_t *ptimer, xv6timer_callback_t callback);
void xv6timer_interrupt(struct xv6timer_t *ptimer);

#endif // XV6TIMER_H
