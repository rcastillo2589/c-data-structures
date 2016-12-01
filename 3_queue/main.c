// Robert Castillo

#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main(void)
{
  queue q;

  queue_init(&q);

  printf("IsEmpty: %s\n", queue_isEmpty(&q) ? "True":"False");
  queue_enqueue(&q, "one");
  queue_enqueue(&q, "two");
  queue_enqueue(&q, "three");
  queue_enqueue(&q, "four");
  queue_enqueue(&q, "five");
  queue_print(&q, "Enqueue 1-5");
  printf("IsEmpty: %s\n", queue_isEmpty(&q) ? "True":"False");

  printf("Dequeue: %s\n", queue_dequeue(&q));
  printf("Dequeue: %s\n", queue_dequeue(&q));
  printf("Dequeue: %s\n", queue_dequeue(&q));
  queue_print(&q, "Dequeued");
}
