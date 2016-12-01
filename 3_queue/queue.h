/*
 * Queue
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
  char *data;
  struct node *next;
} node_t;

typedef struct {
  int length;
  node_t *head;
  node_t *tail;
} queue;

void queue_init(queue *);
void queue_enqueue(queue *, char *);
char* queue_dequeue(queue *);
int queue_isEmpty(queue *);
void queue_print(queue *, char *);
