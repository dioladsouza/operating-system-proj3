/* 
#include "../../kernel/types.h"
#include "../../kernel/param.h" 
#include "../../kernel/memlayout.h" 
#include "../../kernel/riscv.h" 
#include "../../kernel/defs.h" 
#include "../../kernel/spinlock.h"
#include "../../kernel/proc.h"
#include "../../kernel/sleeplock.h"
#include "../../kernel/fs.h"
#include "../../kernel/file.h"
#include "../../kernel/fcntl.h"
#include "proj3/user/user.h"

struct proc proc[NPROC];

int set_cpu_affinity(int cpu_mask) {
    struct proc_p *p;
    struct cpu *c = mycpu();

    c->proc = 0;
    for(;;){
    // The most recent process to run may have had interrupts
    // turned off; enable them to avoid a deadlock if all
    // processes are waiting.
    intr_on();

    int found = 0;
    for(p = proc; p < &proc[NPROC]; p++) {
        acquire(&p->lock);
        if(p->state == RUNNABLE && (p->cpu_affinity == -1 || p->cpu_affinity == cpuid())) {
        // Switch to chosen process.  It is the process's job
        // to release its lock and then reacquire it
        // before jumping back to us.
        p->cpu_affinity = cpu_mask;
        p->state = RUNNING;
        c->proc = p;
        swtch(&c->context, &p->context);

        // Process is done running for now.
        // It should have changed its p->state before coming back.
        c->proc = 0;
        found = 1;
      }
      release(&p->lock);
    }
    if(found == 0) {
      // nothing to run; stop running on this core until an interrupt.
        intr_on();
        asm volatile("wfi");
    }
  }

    return 0;
}
    */

/* 
struct proc_p proc[NPROC];

uint64 sys_set_cpu_affinity(void) {
    struct proc_p *p;
    struct cpu *c = mycpu();

    c->proc = 0;
    for(;;){
    // The most recent process to run may have had interrupts
    // turned off; enable them to avoid a deadlock if all
    // processes are waiting.
    intr_on();

    int found = 0;
    for(p = proc; p < &proc[NPROC]; p++) {
        acquire(&p->lock);
        if(p->state == RUNNABLE && (p->cpu_mask == -1 || p->cpu_mask == cpuid())) {
        // Switch to chosen process.  It is the process's job
        // to release its lock and then reacquire it
        // before jumping back to us.
        p->cpu_mask = cpu_mask;
        p->state = RUNNING;
        c->proc = p;
        swtch(&c->context, &p->context);

        // Process is done running for now.
        // It should have changed its p->state before coming back.
        c->proc = 0;
        found = 1;
      }
      release(&p->lock);
    }
    if(found == 0) {
      // nothing to run; stop running on this core until an interrupt.
        intr_on();
        asm volatile("wfi");
    }
  }

    return 0;
}
*/