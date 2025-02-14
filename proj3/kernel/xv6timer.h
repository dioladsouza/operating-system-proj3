#ifndef XV6TIMER_H
#define XV6TIMER_H

#include "kernel/types.h"  

struct proc;  

struct xv6timer_t;  

typedef void (*xv6timer_callback_t)(struct xv6timer_t *);

struct xv6timer_t {
    int expiry;        
    uint next_tick;        
    struct proc *proc;     
    xv6timer_callback_t callback; 
};

void xv6timer_init(struct xv6timer_t *ptimer, struct proc *proc);
void xv6timer_forward(struct xv6timer_t *ptimer, int expiry);
void xv6timer_register_callback(struct xv6timer_t *ptimer, xv6timer_callback_t callback);
void xv6timer_interrupt(struct xv6timer_t *ptimer);

#endif // XV6TIMER_H
