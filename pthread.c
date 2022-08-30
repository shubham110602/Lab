#include "types.h"
#include "user.h"
#include "x86.h"


#define NULL 0
#define PGSIZE (4096)
int thread_create(void(*fcn)(void*), void *arg, void*stack){
  void *stack = malloc((uint)PGSIZE*2);
  if((uint)stack <= 0){
    printf(1, "Malloc new stack failed in pthread_create\n");
    return -1;
  }
  if((uint)stack % PGSIZE){
    stack += 4096 - ((uint)stack % PGSIZE);
  }
  mpthread_t *thread;
  *thread = clone(func, arg, stack);
  return *thread;
}

void thread_exit(void){
  exit(void)
  return ;
}

