// #include "../../kernel/types.h"
// #include "../../kernel/fs.h"
// #include "../../kernel/param.h"
// #include "../../kernel/memlayout.h"
// #include "../../kernel/riscv.h"
// #include "../../kernel/defs.h"
// #include "../../kernel/spinlock.h"
// #include "../../kernel/proc.h"
// #include "../../kernel/syscall.h"
// #include "../../kernel/sleeplock.h"
// #include "../../kernel/file.h"
// #include "../../kernel/fcntl.h"
// #include "proj3/kernel/xv6timer.h"

// void test_callback(struct xv6timer_t *t) {
//     printf("Timer expired for process at tick %d\n", ticks);
// }

// uint64
// sys_setperiod(void) {
//     int period;
//     argint(0, &period);
//     if (period < 0 || period < 1) {
//         return -1;  // Invalid 
//     }

//     struct proc *p = myproc();
//     p->period = period;  
//     p->next_wakeup = ticks + period; // Schedule next wake-up time

//     xv6timer_register_callback(&p->timer, test_callback);

//     return 0;
// }