#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_THREADS 5
#define ARRAY_SIZE 100

int arrayTOsum[ARRAY_SIZE];
pthread_t thread_ids[NUM_THREADS];

void *threadSumFunc(void *arg) {
    int thread_id = *((int *) arg);
    int start = thread_id * (ARRAY_SIZE / NUM_THREADS);
    int end = start + (ARRAY_SIZE / NUM_THREADS) - 1;
    printf("Thread ID: %d, Start: %d, End: %d\n", thread_id, start, end);

    int *sum = (int *) malloc(sizeof(int));
    *sum = 0;

    for (int i = start; i <= end; i++) {
        *sum += arrayTOsum[i];
    }
	printf("thread %d says, sum = %d\n",thread_id, *sum);
    pthread_exit(sum);
}

int main() {
    srand(time(NULL));
    int total_sum = 0, total_sum2 = 0;

    // Initialize array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arrayTOsum[i] = rand() % 100;
        total_sum += arrayTOsum[i];
    }

    // Create threads
    int thread_args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&thread_ids[i], NULL, threadSumFunc, (void *) &thread_args[i]);
    }

    // Join threads and collect results
    for (int i = 0; i < NUM_THREADS; i++) {
        void *thread_result;
        pthread_join(thread_ids[i], &thread_result);
        total_sum2 += *((int *) thread_result);
        free(thread_result);
    }

    printf("Total sum calculated by main: %d\n", total_sum);
	printf("Total sum calculated by threads: %d\n", total_sum2);

    return 0;
}
