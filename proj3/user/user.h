int set_cpu_affinity(int cpu_mask);
/* 
struct xv6timer_t;

typedef void (*xv6timer_callback_t)(struct xv6timer_t *);

struct xv6timer_t {
  int expiry;    // Number of ticks between interrupts 
  uint next_tick;   // Tick count when the timer should trigger next
  struct proc *proc;  // Associated process 
  void (*callback)(struct xv6timer_t *); // Callback function 
};

void xv6timer_init(struct xv6timer_t *ptimer, struct proc *proc);
void xv6timer_forward(struct xv6timer_t *ptimer, int expiry);
void xv6timer_register_callback(struct xv6timer_t *ptimer, xv6timer_callback_t callback);
void xv6timer_interrupt(struct xv6timer_t *ptimer);
*/

//enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };
// Per-process state
/*
struct proc_p {
  struct spinlock lock;

  // p->lock must be held when using these:
  enum procstate state;        // Process state
  //int pid;                     // Process ID

  // wait_lock must be held when using this:
  //struct proc *parent;         // Parent process

  //char name[16];               // Process name (debugging)

  int cpu_affinity; // Indicates which processor needs to be assigned by the scheduler to run the process/thread
};
*/