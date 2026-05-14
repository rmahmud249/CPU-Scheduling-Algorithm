#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void* worker(void* arg) {
while (1) {
printf("Thread is working...\n");

sleep(1);
}
return NULL;
}
int main() {
pthread_t t;
pthread_create(&t, NULL, worker, NULL);
sleep(3);
pthread_cancel(t);
pthread_join(t, NULL);
printf("Thread has been cancelled\n");
return 0;
}
