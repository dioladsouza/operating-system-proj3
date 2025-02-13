// #include "proj3/user/user.h"
// #include "kernel/types.h"
// #include "kernel/stat.h"
// #include "user/user.h"
// #include "proj3/kernel/xv6timer.h"
// //#include "kernel/proc.h"

// void task() {
//     printf("Process woke up at tick %d\n", uptime());
// }

// int main() {
//     // if (setperiod(10) < 0) {
//     //     printf("Failed to set period\n");
//     //     exit(1);
//     // }

//     // while (1) {
//     //     task(); // Execute periodic task
//     //     wait_until_next_period();
//     // }


//     exit(0);
// }

// /*
// uint ticks;
// struct proc *proc;

// void test_callback(struct xv6timer_t *t) {
//     printf("Timer expired for process at tick %d\n", ticks);
// }

// int main() {
//     struct xv6timer_t mytimer;
//     xv6timer_init(&mytimer, proc);
//     xv6timer_register_callback(&mytimer, test_callback);
//     xv6timer_forward(&mytimer, 10);

//     while (1) {
//         sleep(5);
//         printf("Waiting\n");
//     }
// }
// */



#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "proj3/kernel/xv6timer.h"

// Callback function to test timer execution
void my_callback(struct xv6timer_t *timer) {
    printf("Timer callback executed for process %d\n", getpid());
}

int main() {
    // struct xv6timer_t my_timer;

    // // Initialize the timer using myproc() from the kernel via a syscall or user-space alternative
    // xv6timer_init(&my_timer, myproc());  // ❌ Fix: getpid() → ✅ myproc()

    // xv6timer_register_callback(&my_timer, my_callback);
    
    // // Set the timer to expire in 5 ticks
    // xv6timer_forward(&my_timer, 5);

    // printf("Waiting for timer...\n");
    
    // // Simulate a loop that waits for the timer
    // for (int i = 0; i < 10; i++) {
    //     sleep(1); // Each sleep represents one tick
    //     printf("Tick %d\n", i);
    // }

    exit(0);
}
