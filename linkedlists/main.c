// Robert Castillo

#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(void)
{
  linkedlist llist;

  linked_list_init(&llist);
  linked_list_push_back(&llist, "one");
  linked_list_push_back(&llist, "two");

  printf("%d\n", linked_list_size(&llist));
  printf("%s\n", (char *)linked_list_front(&llist));
  printf("%s\n", (char *)linked_list_back(&llist));
}
