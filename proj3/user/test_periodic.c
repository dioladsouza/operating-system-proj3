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

void periodic_task(int period) {
    setperiod(period);

    // Run periodic task
    for (int i = 0; i < 3; i++) {  // Run a few iterations
        printf("Process %d executing task\n", getpid());

        // Print current tick and next tick with %p for uint64
        printf("xv6timer_forward: current tick %ld, next tick set at %ld\n", getticks(), getticks() + period);
        wait_until_next_period();
    }

    printf("Process %d finished\n", getpid());
}

int main() {
    periodic_task(10); 


    printf("Test complete\n");
    exit(0);
}
