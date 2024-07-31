#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 100 // Size of the array
#define NUM_THREADS 5

int array[N];
pthread_t threads[NUM_THREADS];
int partial_sums[NUM_THREADS] = {0}; // Store results of each thread

void* sum_array(void* thread_id) {
    int tid = (int)thread_id;
    int start = tid * (N / NUM_THREADS);
    int end = (tid + 1) * (N / NUM_THREADS);
    int sum = 0;

    for (int i = start; i < end; i++) {
        sum += array[i];
    }

    if (tid == 0) {
        for (int i = 1; i < NUM_THREADS; i++) {
            void* status;
            pthread_join(threads[i], &status);
            sum += (int)status;
            free(status); 
        }
        int *result = malloc(sizeof(int));
        *result = sum;
        pthread_exit((void*) result);
    } else {
        int *partial_sum = malloc(sizeof(int));
        *partial_sum = sum;
        pthread_exit((void*) partial_sum);
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Fill the array with random numbers (1-100)
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 100 + 1;
    }

    // Create threads
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, sum_array, (void*)&thread_ids[i]);
    }

    // Collect result from thread 0
    void* total_sum;
    pthread_join(threads[0], &total_sum);

    // Print the final sum
    printf("Total sum: %d\n", (int)total_sum);

    // Free the dynamically allocated memory
    free(total_sum);

    return 0;
}
