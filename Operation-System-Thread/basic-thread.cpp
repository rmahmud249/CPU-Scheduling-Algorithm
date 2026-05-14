#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* show_message(void* arg) {
    printf("Thread is running\n");
    printf("Thread ID: %lu\n", pthread_self());

    return NULL;
}
//=================================
//gcc thread_program.c -o thread_program -lpthread
//./thread_program
//=================================
int main() {
    pthread_t t1, t2;


    pthread_create(&t1, NULL, show_message, NULL);
    pthread_create(&t2, NULL, show_message, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads have completed execution\n");

    return 0;
}
