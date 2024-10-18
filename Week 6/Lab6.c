/**********************************************************************************
* Conner Jordan
*  334 Sp 23 Lab6 Step 2                                                        *
*  Description: synchronizing two threads using semaphores to safely
   share a finite buffer.
*
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 26

char buffer[BUFFER_SIZE];
int nextIn = 0;
int nextOut = 0;

sem_t empty;
sem_t full;
sem_t mutex;

char produce_item()
{
    return 'A' + (nextIn % BUFFER_SIZE);
}

void insert_item(char item)
{
    buffer[nextIn] = item;
    nextIn = (nextIn + 1) % BUFFER_SIZE;
}

void consume_item(char item)
{
    printf("Consumed: %c\n", item);
}

char remove_item()
{
    char item = buffer[nextOut];
    nextOut = (nextOut + 1) % BUFFER_SIZE;
    return item;
}

void *producer(void *param)
{
    int i;
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        char item = produce_item();
        sem_wait(&empty);
        sem_wait(&mutex);
        insert_item(item);
        printf("Produced: %c\n", item);
        sem_post(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *param)
{
    int i;
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        char item = remove_item();
        sem_post(&mutex);
        sem_post(&empty);
        consume_item(item);
    }

    return NULL;
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}