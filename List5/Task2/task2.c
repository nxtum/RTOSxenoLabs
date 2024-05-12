#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#include <alchemy/task.h>
#include <alchemy/timer.h>
#include <alchemy/sem.h>

#define ITER 10

static RT_TASK t1;
static RT_TASK t2;
static RT_SEM sem;

int global = 0;

void taskOne(void *arg)
{
    int i;
    // Pends on a semaphore, infinite timeout
    //increment global var
    // unbinds sem
        for (i = 0; i < ITER; i++) {
            rt_sem_p(&sem, TM_INFINITE); 
            printf("global:%d\n", ++global);
            rt_sem_v(&sem); 
            rt_task_sleep(1000000); 
        }
        
}

void taskTwo(void *arg)
{
    int i;
    // Pends on a semaphore, infinite timeout
    //decrement global var
    // unbinds sem
        for (i = 0; i < ITER; i++) {
            rt_sem_p(&sem, TM_INFINITE); 
            printf("global:%d\n", --global);
            rt_sem_v(&sem); 
            rt_task_sleep(1000000); 
        }
        
    
}

int main(int argc, char* argv[]) {
    rt_sem_create(&sem, "Semaphore", 1, S_FIFO); // initial val of 1 since need to start the function

    
    rt_task_create(&t1, "task1", 0, 99, 0);
    rt_task_create(&t2, "task2", 0, 99, 0);
    rt_task_start(&t1, &taskOne, 0);
    rt_task_start(&t2, &taskTwo, 0);


    rt_task_join(&t1);
    rt_task_join(&t2);
    pause();

    rt_sem_delete(&sem);
    
    return 0;
}
