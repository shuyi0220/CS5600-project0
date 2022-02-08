#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H
/**
 * Type definition of a Process with its identifier and name field.
 */
typedef struct _process {
    int PID;    //process identifier
    char *name;    //process name
} process_t;


/**
 * Type definition of linked queue node with process and next node field.
 */
typedef struct _node {
    process_t* p;    //current process
    struct _node *next;
} node_t;

/**
 * Type definition of generic queue
 */
typedef struct _queue {
    void *data;
} queue_t;

node_t *front;
node_t *rear;


int isempty(queue_t *queue);

void initialize(queue_t *queue);

void display(node_t *head);

void enqueue(queue_t *queue, void *element);

void* dequeue(queue_t *queue);


#endif
