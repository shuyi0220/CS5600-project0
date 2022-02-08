#include "queue.h"


void initialize(queue_t *queue) {
  queue->data = NULL;
  front = NULL;
  rear = NULL;
}

int isempty(queue_t *queue)
{
    return (rear == NULL);
}

void display(node_t *head)
{
    if (head == NULL) {
        printf("NULL\n");
    }
    else {
        printf("[id: %d, name: %s]->", head->p->PID, head->p->name);
        display(head->next);
    }
}

void enqueue(queue_t *queue, void *element)
{
    node_t *tmp;
    tmp = (node_t *) malloc(sizeof(*tmp));
    tmp->p = element;
    tmp->next = NULL;
    if (!isempty(queue)) {
        rear->next = tmp;
        rear = tmp;
    }
    else {
        queue->data = front = rear = tmp;
    }
}

void* dequeue(queue_t *queue)
{
    node_t *tmp;
    process_t* n = front->p;
    tmp = front;
    front = front->next;
    queue->data = front;
    free(tmp);
    return n;
}
