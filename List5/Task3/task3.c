#include <stdio.h>
#include <math.h>

#include <alchemy/task.h>
#include <alchemy/queue.h>

#define QUEUE_SIZE 10
#define NUM_TASKS 5 // num of processes

RT_TASK t[NUM_TASKS];
RT_QUEUE queue;

double monte_carlo(int points) {
    int circle = 0;
    for (int i = 0; i < points; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            circle++;
        }
    }
    return 4.0 * circle / points;
}

void process(void *arg) {
    // cast arg into int
    int num_points = *(int *)arg;
    double pi = monte_carlo(num_points);

    // once value gets returned from monte_carlo,
    // send this value to main queue
    rt_queue_write(&queue, &pi, sizeof(pi), Q_NORMAL);
}

int main() {
    int num_points;

    printf("Number of points: ");
    scanf("%d", &num_points);

    // main queue: queue, name, poolsize, qlimit, mode
    rt_queue_create(&queue, "pi_queue", sizeof(double), QUEUE_SIZE, Q_FIFO);

    // tasks
    for (int i = 0; i < NUM_TASKS; i++) {
       rt_task_create(&t[i], "process", 0, 99, 0);
       rt_task_start(&t[i], &process, &num_points);
    }

    double total_pi = 0;

    // receive pi values
    for (int i = 0; i < NUM_TASKS; i++) {
        double pi;
        rt_queue_read(&queue, &pi, sizeof(pi), TM_INFINITE);
        total_pi += pi;
    }

    // mean value from all processes
    double mean_pi = total_pi / NUM_TASKS;
    printf("Estimated value of pi: %f\n", mean_pi);

    
    rt_queue_delete(&queue);

    return 0;
}
