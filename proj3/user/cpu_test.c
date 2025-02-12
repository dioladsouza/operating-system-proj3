#include "proj3/user/user.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() { 
    
    int cpuid = 0; 
    set_cpu_affinity(1 << cpuid);   /* pin the process to cpu 0 */
    printf("CPU affinity set to %d\n", cpuid);
    exit(0); 
} 
