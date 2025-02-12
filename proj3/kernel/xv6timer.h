#include "kernel/types.h"
struct xv6timer_t;

typedef void (*xv6timer_callback_t) (struct xv6timer_t *);

struct xv6timer_t {
  int expiry;    // Number of ticks between interrupts 
  uint next_tick;   // Tick count when the timer should trigger next
  struct proc *proc;  // Associated process 
  void (*callback)(struct xv6timer_t *); // Callback function 
};

void xv6timer_init(struct xv6timer_t *ptimer, struct proc *proc);
void xv6timer_forward(struct xv6timer_t *ptimer, int expiry);
void xv6timer_register_callback(struct xv6timer_t *ptimer, void (*callback)(struct xv6timer_t *));
void xv6timer_interrupt(struct xv6timer_t *ptimer);