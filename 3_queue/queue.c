/*
 * Queue
 */

#include "queue.h"

void queue_init(queue *q)
{
  q->head = NULL;
  q->tail = NULL;
  q->length = 0;
}

void queue_enqueue(queue *q, char *value)
{
  node_t *current = NULL;
  node_t *newValue = malloc(sizeof(node_t));
  newValue->data = value;
  newValue->next = NULL;

  if(q->tail == NULL) {
    q->tail = newValue;
    q->head = newValue;
    q->length++;
  } else {
    current = q->tail;
    current->next = newValue;
    q->tail = current->next;
  }
}

char* queue_dequeue(queue *q)
{
  node_t *current = NULL;

  if(q->tail == NULL) {
    return NULL;
  } else {
    current = q->head;
    q->head = current->next;
    q->length--;
    return current->data;
  }
}

int queue_isEmpty(queue *q)
{
  if(q->length == 0) {
    return 1;
  } else {
    return 0;
  }
}

void queue_print(queue *q, char *operation)
{
  node_t *current = NULL;

  current = q->head;

  printf("%s: ", operation);
  while(current != NULL) {
    printf("%s,", current->data);
    current = current->next;
  }
  printf("\n");
}
