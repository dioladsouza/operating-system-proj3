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

// void periodic_task(int period) {
//     setperiod(period);

//     // Run periodic task
//     for (int i = 0; i < 3; i++) {  // Run a few iterations
//         printf("Process %d executing task\n", getpid());

//         // Print current tick and next tick with %p for uint64
//         printf("xv6timer_forward: current tick %ld, next tick set at %ld\n", getticks(), getticks() + period);
//         wait_until_next_period();
//     }

//     printf("Process %d finished\n", getpid());
// }

// int main() {
//     periodic_task(10); 


//     printf("Test complete\n");
//     exit(0);
// }



// #include "kernel/types.h"
// #include "kernel/stat.h"
// #include "user/user.h"
// #include "proj3/user/user.h"

// Function to simulate periodic task behavior
void periodic_task(int period) {
    setperiod(period);  // Set the task period
    
    // Run periodic task for a few iterations
    for (int i = 0; i < 3; i++) {
        printf("Process %d executing task\n", getpid());
        printf("xv6timer_forward: current tick %ld, next tick set at %ld\n", getticks(), getticks() + period);
        wait_until_next_period();  // Wait for the next period
    }
    printf("Process %d finished\n", getpid());
}

int main() {
    // Test 4 periodic tasks
    printf("[DEBUG] Starting test with 4 periodic tasks\n");

    // Task 1: Period 5
    if (fork() == 0) {
        periodic_task(10); // First task wakes up every 5 ticks
        exit(0);
    }
    
    // Task 2: Period 10
    if (fork() == 0) {
        periodic_task(5); // Second task wakes up every 10 ticks
        exit(0);
    }
    
    // Task 3: Period 15
    if (fork() == 0) {
        periodic_task(15); // Third task wakes up every 15 ticks
        exit(0);
    }
    
    // Task 4: Period 20
    if (fork() == 0) {
        periodic_task(1); // Fourth task wakes up every 20 ticks
        exit(0);
    }

    // Try adding a 5th periodic task (should be rejected)
    if (fork() == 0) {
        printf("[DEBUG] Attempting to add 5th periodic task\n");
        if (setperiod(25) == -1) {
            printf("[DEBUG] Failed to add 5th periodic task, task limit reached\n");
        }
        exit(0);
    }

    // Wait for all child processes to finish
    wait(0);
    wait(0);
    wait(0);
    wait(0);

    printf("Test complete\n");
    exit(0);
}
