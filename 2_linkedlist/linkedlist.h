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
void linked_list_print(linkedlist *);
int linked_list_size(linkedlist *);
int linked_list_empty(linkedlist *);
char* linked_list_value_at(linkedlist *, int);
void linked_list_push_front(linkedlist *, char *);
char* linked_list_pop_front(linkedlist *);
void linked_list_push_back(linkedlist *, char *);
char* linked_list_pop_back(linkedlist *);
char* linked_list_front(linkedlist *);
char* linked_list_back(linkedlist *);
void linked_list_insert(linkedlist *, int, char *);
void linked_list_erase(linkedlist *, int);
char* linked_list_value_from_end(linkedlist *, int);
void linked_list_reverse(linkedlist *);
void linked_list_remove(linkedlist *, char *);
