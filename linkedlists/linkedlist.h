/*
 * LinkedList
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
} linkedlist;

void linked_list_init(linkedlist *);
int linked_list_size(linkedlist *);
int linked_list_empty(linkedlist *);
char* linked_list_value_at(linkedlist *, int);
void linked_list_push_front(linkedlist *, char *);
char* linked_list_pop_front(linkedlist *);
void linked_list_push_back(linkedlist *, char *);
char* linked_list_pop_back(linkedlist *);
char* linked_list_front(linkedlist *);
char* linked_list_back(linkedlist *);

/*
 insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
 erase(index) - removes node at given index
 value_n_from_end(n) - returns the value of the node at nth position from the end of the list
 reverse() - reverses the list
 remove_value(value) - removes the first item in the list with this value
 */
