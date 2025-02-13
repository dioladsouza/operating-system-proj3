#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "proj3/user/user.h"


// int main() {
//     setperiod(10);  // Set period to 10 ticks

//     for (int i = 0; i < 5; i++) {  // Run a few iterations
//         printf("Process %d executing task\n", getpid());
//         wait_until_next_period();
//     }

//     printf("Process %d finished\n", getpid());
//     exit(0);
// }



// #include "kernel/types.h"
// #include "kernel/stat.h"
// #include "user/user.h"
// #include "proj3/user/user.h"
#include "proj3/kernel/xv6timer.h"

// Declare ticks as an external variable
extern uint ticks;  // Make sure this points to the global ticks variable in the kernel

void periodic_task(int period) {
    setperiod(period);

    // Print current time at the start of each task
    for (int i = 0; i < 3; i++) {  // Run a few iterations
        printf("Process %d executing task\n", getpid());

        // Debugging: print current tick and next tick when forwarding
        printf("xv6timer_forward: current tick %d, next tick set at %d\n", ticks, ticks + period);
        wait_until_next_period();
    }

    printf("Process %d finished\n", getpid());
}

int main() {
    periodic_task(5); // Use only one process and wake up every 5 ticks

    printf("Test complete\n");
    exit(0);
}
