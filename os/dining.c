#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM 5 

sem_t chopstick[NUM];

void *philosopher(void *num) {
    int id = *(int *)num;

    printf("Philosopher %d is thinking...\n", id);
    sleep(1);

    
    sem_wait(&chopstick[id]);
   
    sem_wait(&chopstick[(id + 1) % NUM]);

    printf("Philosopher %d is eating...\n", id);
    sleep(2);

   
    sem_post(&chopstick[id]);
    sem_post(&chopstick[(id + 1) % NUM]);

    printf("Philosopher %d finished eating.\n", id);

    return NULL;
}

int main() {
    int i;
    pthread_t thread[NUM];
    int philosopher_id[NUM];

    
    for (i = 0; i < NUM; i++)
        sem_init(&chopstick[i], 0, 1);

   
    for (i = 0; i < NUM; i++) {
        philosopher_id[i] = i;
        pthread_create(&thread[i], NULL, philosopher, &philosopher_id[i]);
    }


    for (i = 0; i < NUM; i++)
        pthread_join(thread[i], NULL);


    for (i = 0; i < NUM; i++)
        sem_destroy(&chopstick[i]);

    return 0;
}
