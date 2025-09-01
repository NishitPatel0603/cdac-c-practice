#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 12         // Adjust according to your CPU
#define ALLOC_MB_PER_THREAD 1000  // RAM usage per thread in MB
#define RUN_TIME_SECONDS 18000    // Total time to run the test

void* stress_test(void* arg) {
    size_t size = ALLOC_MB_PER_THREAD * 1024 * 1024;
    char* mem = malloc(size);
    
    if (!mem) {
        perror("Memory allocation failed");
        pthread_exit(NULL);
    }

    // Fill memory with data to ensure physical allocation
    for (size_t i = 0; i < size; ++i) {
        mem[i] = (char)(i % 256);
    }

    // Busy loop to max out CPU
    time_t end = time(NULL) + RUN_TIME_SECONDS;
    while (time(NULL) < end) {
        for (int i = 0; i < size; i++) {
            mem[i] = mem[i] ^ 0xFF; // Arbitrary CPU work
        }
    }

    free(mem);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_COUNT];

    printf("Starting stress test with %d threads...\n", THREAD_COUNT);

    for (int i = 0; i < THREAD_COUNT; ++i) {
        if (pthread_create(&threads[i], NULL, stress_test, NULL)) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < THREAD_COUNT; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Stress test completed.\n");

    return 0;
}
