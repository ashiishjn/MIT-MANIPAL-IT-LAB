#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t db, mutex;
int readcount = 0;

void *writer(void * a){
    int arg = (int)a;
    sem_wait(&db);
    printf("W - Writer %d is operating\n", arg);
    printf("W - Writer %d done\n",arg);
    sem_post(&db);
}

void *reader(void * a){
    int arg = (int) a;
    sem_wait(&mutex);
    readcount++;
    if(readcount == 1)
        sem_wait(&db);
    sem_post(&mutex);
    printf("R - Reader %d is operating\n",arg);
    sem_wait(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&db);
    printf("R - Reader %d done\n",arg);
    sem_post(&mutex);
}

int main(){
    int r, w;
    printf("Enter the number of readers and writers: ");
    scanf("%d %d", &r, &w);
    pthread_t readers[r], writers[w];
    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);
    int i=0;
    while(i<r||i<w){
        if(i<r)
            pthread_create(&readers[i], NULL, reader,(void *)i+1);
        if(i<w)
            pthread_create(&writers[i], NULL, writer,(void *)i+1);
        i++;
    }
    i=0;
    while(i<r || i<w){
        if(i<r)
            pthread_join(readers[i], NULL);    
        if(i<w)
            pthread_join(writers[i], NULL);
        i++; 
    }
    sem_destroy(&mutex);
    sem_destroy(&db);
    return 0;
}

// Compile using -lpthread -lrt -w flag
// For example: gcc 1.c -lpthread -lrt -w