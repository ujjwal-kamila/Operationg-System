#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_THREADS 5
#define ARRAY_SIZE 100

int arrayTOsum[ARRAY_SIZE];
pthread_t thread_ids[NUM_THREADS];

void *threadSumFunc_0(void *arg){
    int thread_id = *((int *) arg); //***  yaha void pointer ko int pointer karke de-reference kar rahe hai
    int start = thread_id * (ARRAY_SIZE / NUM_THREADS); // 0-19
    int end = start + (ARRAY_SIZE / NUM_THREADS) - 1;
    // printf("Thread ID: %d, Start: %d, End: %d\n", thread_id, start, end);
    int total_sum2 = 0;

    for (int i = start; i <= end; i++) {
        total_sum2 += arrayTOsum[i];//self calculation
    }
    for (int i = 1; i < NUM_THREADS; i++) {
        void *thread_result;
        pthread_join(thread_ids[i], &thread_result);//wait for the other threads
        total_sum2 += *((int *) thread_result);//add the return value to total sum
        free(thread_result);
    }
    int *sum = (int *) malloc(sizeof(int));
    *sum = total_sum2;

    pthread_exit(sum);
}

void *threadSumFunc(void *arg) {
    int thread_id = *((int *) arg);
    int start = thread_id * (ARRAY_SIZE / NUM_THREADS); // 20-39 ||40-59 ||60-79 ||80-99
    int end = start + (ARRAY_SIZE / NUM_THREADS) - 1;
    printf("Thread ID: %d, Start: %d, End: %d\n", thread_id, start, end);

    int *sum = (int *) malloc(sizeof(int)); //return value ke liye karna pad raha hai
    *sum = 0;

    for (int i = start; i <= end; i++) {
        *sum += arrayTOsum[i];//calculate own sum 
    }
	printf("thread %d says, sum = %d\n",thread_id, *sum);
    pthread_exit(sum); //return own sum
}

int main() {
    srand(time(NULL));
    int total_sum = 0;//storing total as we go
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arrayTOsum[i] = rand() % 100;
        total_sum += arrayTOsum[i];
    }

    // Create threads
    int thread_args[NUM_THREADS];
    for (int i = 1; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&thread_ids[i], NULL, threadSumFunc, (void *) &thread_args[i]);
        //create threads form 1 to 4
    }

    thread_args[0] = 0;
    pthread_create(&thread_ids[0], NULL, threadSumFunc_0, (void *) &thread_args[0]);//create 0th thread

    // Join threads and collect results
    void *thread_result;
    pthread_join(thread_ids[0], &thread_result); //join 0th thread
    int total_sum2 = *((int *) thread_result);

    printf("Total sum calculated by main: %d\n", total_sum);
	printf("Total sum calculated by threads: %d\n", total_sum2);

    return 0;
}
