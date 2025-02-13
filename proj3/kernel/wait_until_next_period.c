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

// uint64
// sys_wait_until_next_period(void) {
//     struct proc *p = myproc();
//     acquire(&p->lock);

//     while (ticks < p->next_wakeup) {
//         sleep(p, &p->lock);
//     }

//     // Set next wakeup
//     p->next_wakeup += p->period;

//     release(&p->lock);
//     return 0;
// }