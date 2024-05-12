#include <stdio.h>
#include <unistd.h>

#include <alchemy/timer.h>
#include <alchemy/task.h>

RT_TASK demo_t;
    

void demo(void *arg) {
    // task set periodic is in nanoseconds, so this is 1 second
  rt_task_set_periodic(NULL, TM_NOW, 1000000000);
  RTIME now;
 
  while (1) {
    now = rt_timer_read();
    printf("Test\n");
    rt_task_wait_period(NULL);
  }
  return;
}

int main() {


    rt_task_create(&demo_t, "timer",0,99,0);
    rt_task_start(&demo_t, &demo, 0);
    pause();
    return 0;
} 
