#include <stdio.h>
#include <alchemy/task.h>
#include <alchemy/buffer.h>
#include <alchemy/sem.h>

#define BUFFSIZE 10000

RT_TASK task1;
RT_TASK task2;
RT_BUFFER buff;
RT_SEM sem_receiver;
RT_SEM sem_sender;

void reader(void *arg) {
    char text[BUFFSIZE];
    int size;
    FILE *outputf = fopen("t8.shakespeare-a.txt", "w");
    if (outputf == NULL) {
        printf("Ouput file error\n");
        exit(-1);
    }

    while (1) {
        rt_sem_p(&sem_receiver, TM_INFINITE); // wait for sender to finish

        rt_buffer_read(&buff, &size, sizeof(int), TM_INFINITE);
        if (size == 0) {
            break; // checks size of reader
        }

        rt_buffer_read(&buff, text, size, TM_INFINITE);
        fwrite(text, 1, size, outputf);

        rt_sem_v(&sem_sender); // sender to start writing
    }

    fclose(outputf);
    exit(EXIT_SUCCESS);
}

void writer(void *arg) {
    char text[BUFFSIZE];
    int cntr;
    FILE *inputf = fopen("t8.shakespeare.txt", "r");
    if (inputf == NULL) {
        printf("Input file error\n");
        exit(-1);
    }

    while ((cntr = fread(text, 1, BUFFSIZE, inputf)) > 0) {
        rt_sem_p(&sem_sender, TM_INFINITE); // wait for reader to finish

        rt_buffer_write(&buff, &cntr, sizeof(int), TM_INFINITE);
        rt_buffer_write(&buff, text, cntr, TM_INFINITE);

        rt_sem_v(&sem_receiver); // reader to start
    }

    rt_buffer_write(&buff, &cntr, sizeof(int), TM_INFINITE);
    fclose(inputf);
    exit(EXIT_SUCCESS);
}

int main() {
    rt_buffer_create(&buff, "sp", BUFFSIZE + sizeof(int), B_FIFO);

    rt_sem_create(&sem_receiver, "receiver", 0, S_FIFO);
    rt_sem_create(&sem_sender, "sender", 1, S_FIFO);

    rt_task_create(&task1, "Reader", 0, 99, 0);
    rt_task_create(&task2, "Writer", 0, 99, 0);

    rt_task_start(&task1, &reader, 0);
    rt_task_start(&task2, &writer, 0);

    rt_task_join(&task1);
    rt_task_join(&task2);
}
   
