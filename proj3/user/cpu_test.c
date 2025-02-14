#include "proj3/user/user.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "../kernel/getcpuid.h"


int main() {
    int cpu_before = getcpuid();
    printf("Process started on CPU %d\n", cpu_before);

    set_cpu_affinity(1 << 1);  
    sleep(10);  

    int cpu_after = getcpuid();
    printf("Process running on CPU %d after setting affinity\n", cpu_after);

    while (1) {
        printf("Process running on CPU %d\n", getcpuid());
        sleep(10);
    }

    exit(0);
}
