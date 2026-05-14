#include <stdio.h>
#include <pthread.h>
int main() {
pthread_t t1, t2;
t1 = pthread_self();
t2 = pthread_self();
if (pthread_equal(t1, t2))
printf("Both thread IDs are equal\n");
else
printf("Both thread IDs are not equal\n");
return 0;
}
