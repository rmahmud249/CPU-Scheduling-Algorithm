#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* task(void* arg) {
    int id = *(int*)arg;

    printf("Thread %d started\n", id);
    sleep(2);
    printf("Thread %d finished after sleeping\n", id);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    int a = 1, b = 2;

    // Create threads
    pthread_create(&t1, NULL, task, &a);
    pthread_create(&t2, NULL, task, &b);

    // Wait for threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread finished\n");

    return 0;
}
