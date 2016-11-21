// Robert Castillo

#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(void)
{
  linkedlist llist;

  linked_list_init(&llist);
  printf("IsEmpty: %s\n", linked_list_empty(&llist) ? "true":"false");
  linked_list_push_back(&llist, "one");
  linked_list_push_back(&llist, "two");
  linked_list_push_back(&llist, "three");

  linked_list_print(&llist);

  printf("Size: %d\n", linked_list_size(&llist));
  printf("Front: %s\n", linked_list_front(&llist));
  printf("Back: %s\n", linked_list_back(&llist));

  printf("Value at 1: %s\n", linked_list_value_at(&llist, 1));

  linked_list_push_front(&llist, "zero");
  linked_list_push_front(&llist, "neg-one");

  linked_list_print(&llist);

  printf("Pop front: %s\n", linked_list_pop_front(&llist));
  printf("Pop back: %s\n", linked_list_pop_back(&llist));

  linked_list_print(&llist);

  linked_list_insert(&llist, 1, "four");
  linked_list_insert(&llist, 1, "five");
  linked_list_insert(&llist, 2, "six");

  linked_list_print(&llist);

  linked_list_erase(&llist, 3);
  linked_list_erase(&llist, 0);

  linked_list_print(&llist);

  printf("1 from end: %s\n", linked_list_value_from_end(&llist, 1));
  printf("2 from end: %s\n", linked_list_value_from_end(&llist, 2));

  linked_list_reverse(&llist);
  linked_list_print(&llist);

  linked_list_remove(&llist, "six");
  linked_list_remove(&llist, "one");

  linked_list_reverse(&llist);
  linked_list_print(&llist);
}
