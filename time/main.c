#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <limits.h>

#define ARRAY_SIZE 1000000
#define REPEAT 10

int *array;
int global_max = INT_MIN;
pthread_mutex_t mutex;

typedef struct {
    int start_index;
    int end_index;
    int thread_max;
} ThreadArgs;

void *find_max(void *args) {
    ThreadArgs *thread_args = (ThreadArgs *)args;
    int local_max = INT_MIN;

    for (int i = thread_args->start_index; i <= thread_args->end_index; i++) {
        if (array[i] > local_max) {
            local_max = array[i];
        }
    }

    pthread_mutex_lock(&mutex);
    if (local_max > global_max) {
        global_max = local_max;
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int find_max_sequential(int *array, int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

double measure_time(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    int num_threads;
    struct timespec start, end;
    double seq_time = 0, par_time = 0;

    FILE *file = fopen("results.txt", "w");
    if (!file) {
        perror("Error opening results.txt");
        return EXIT_FAILURE;
    }


    array = malloc(ARRAY_SIZE * sizeof(int));
    if (!array) {
        perror("Failed to allocate memory");
        fclose(file);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100000;
    }


    printf("Enter the number of threads: ");
    if (scanf("%d", &num_threads) != 1 || num_threads <= 0) {
        fprintf(stderr, "Invalid number of threads.\n");
        fclose(file);
        free(array);
        return EXIT_FAILURE;
    }

    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));
    ThreadArgs *thread_args = malloc(num_threads * sizeof(ThreadArgs));
    pthread_mutex_init(&mutex, NULL);


    clock_gettime(CLOCK_MONOTONIC, &start);
    int sequential_max = find_max_sequential(array, ARRAY_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end);
    seq_time = measure_time(start, end);

    printf("Sequential Max: %d, Time: %.6f seconds\n", sequential_max, seq_time);
    fprintf(file, "Threads Sequential_Time Parallel_Time\n"); // Write header to results.txt


    for (int rep = 0; rep < REPEAT; rep++) {
        clock_gettime(CLOCK_MONOTONIC, &start);

        int chunk_size = ARRAY_SIZE / num_threads;
        global_max = INT_MIN;

        for (int i = 0; i < num_threads; i++) {
            thread_args[i].start_index = i * chunk_size;
            thread_args[i].end_index = (i == num_threads - 1) ? ARRAY_SIZE - 1 : (i + 1) * chunk_size - 1;

            if (pthread_create(&threads[i], NULL, find_max, &thread_args[i]) != 0) {
                perror("Error creating thread");
                free(array);
                free(threads);
                free(thread_args);
                pthread_mutex_destroy(&mutex);
                fclose(file);
                return EXIT_FAILURE;
            }
        }

        for (int i = 0; i < num_threads; i++) {
            pthread_join(threads[i], NULL);
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        par_time = measure_time(start, end);

        printf("Parallel Max: %d, Time: %.6f seconds\n", global_max, par_time);
        fprintf(file, "%d %.6f %.6f\n", num_threads, seq_time, par_time);
    }


    pthread_mutex_destroy(&mutex);
    free(array);
    free(threads);
    free(thread_args);
    fclose(file);

    return 0;
}
