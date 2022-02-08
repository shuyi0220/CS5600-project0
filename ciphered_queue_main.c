#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "caesar.h"
#define MAX_NUMBER_OF_PROCESS    4    

int main(void) {
  queue_t *queue;
  queue = (queue_t *) malloc(sizeof(*queue));
  initialize(queue);
  int key;
  getKey(&key);

  printf("\n");
  printf("Queue Before Enqueue:\n");
  printf("--------------------------\n");
  display(queue->data);

  printf("\n");
  printf("Queue After Enqueue\n");
  printf("--------------------------\n");

  process_t process[MAX_NUMBER_OF_PROCESS];
  char* c;
  c = (char*)malloc(sizeof(char));
  *c = 'A';
  for (int i=1;i<MAX_NUMBER_OF_PROCESS;i++) {
    process_t *p = &process[i];
    p->PID = i;
    p->name = malloc(sizeof(*p->name)*9);
    encode(c, key);
    sprintf(p->name, "%s", c);

    enqueue(queue, p);
    printf("Enqueued:[id: %d, name: %s] is enqueued.\t", p->PID, p->name);
    display(queue->data);
    *c = 'A' + i;
  }


  printf("\n");
  printf("Queue Before Dequeue\n");
  printf("--------------------------\n");
  display(queue->data);

  printf("\n");
  printf("Queue After Dequeue\n");
  printf("--------------------------\n");

  for (int i=1;i<MAX_NUMBER_OF_PROCESS;i++) {
      process_t* dequeuedProcess =  dequeue(queue);
      printf("Dequeued:[id: %d, name: %s] is dequeued.\t",dequeuedProcess->PID ,dequeuedProcess->name);
      display(queue->data);
  }

  free(queue);
  return 0;

}
