#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

int capacity;
int *queue;
int max;
sem_t full, empty;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer( void * param){
    int in = 0;
    for ( int i=0; i<max; i++ ){
        sem_wait(&empty);  //Wait for post on empty
        pthread_mutex_lock( &mutex );
        queue[in] = i+1;
        in = (in+1)%capacity;
        printf("Produced %d\n", i+1);
        pthread_mutex_unlock( &mutex );
        sem_post( &full );  //Signal full
    }
}
void *consumer(void * param){
    int out = 0;
    for ( int i=0; i<max; i++ ){
        sem_wait(&full);  //Wait for post on full
        pthread_mutex_lock( &mutex );
        printf("Consumed %i\n", queue[out]);
        out= (out+1)%capacity;
        pthread_mutex_unlock( &mutex );
        sem_post(&empty);  //Signal empty
    }
}
int main(){
    printf("Enter the size of the buffer: ");
    scanf("%d", &capacity);
    printf("Enter the number of items to produce: ");
    scanf("%d", &max);
    queue = malloc((capacity) *sizeof(int));

    pthread_t threads[2];
    sem_init( &full, 0, 0 );
    sem_init( &empty, 0, capacity);
    pthread_create( &threads[0], 0, producer, 0 );
    pthread_create( &threads[1], 0, consumer, 0 );
    pthread_join( threads[0], 0 );
    pthread_join( threads[1], 0 );
    sem_destroy( &full );
    sem_destroy( &empty );
}

// Compile using -lpthread -lrt flag
// For example: gcc 1.c -lpthread -lrt