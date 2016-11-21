/*
 * linkedlist
 */

#include "linkedlist.h"

void linked_list_init(linkedlist *ll)
{
  ll->head = NULL;
  ll->length = 0;
}

void linked_list_print(linkedlist *ll)
{
  int i;
  node_t *current;

  if(ll->head != NULL) {
    current = ll->head;

    printf("(LOOP START)\n");
    while(current != NULL) {
      printf("%s\n", current->data);
      current = current->next;
    }
    printf("(LOOP END)\n");
  }
}

int linked_list_size(linkedlist *ll)
{
  return ll->length;
}

int linked_list_empty(linkedlist *ll)
{
  if(ll->length == 0) {
    return 1;
  } else {
    return 0;
  }
}

char* linked_list_value_at(linkedlist *ll, int position)
{
  int count;
  node_t *current;
  node_t *value;

  if(ll->head == NULL) {
    return NULL;
  } else {
    count = 0;
    current = ll->head;

    while(current != NULL) {
      if(count == position) {
        value = current;
      }

      current = current->next;
      count++;
    }

    return value->data;
  }
}

void linked_list_push_front(linkedlist *ll, char *value)
{
  node_t *current;
  node_t *newValue = malloc(sizeof(node_t));
  newValue->data = value;
  newValue->next = NULL;

  if(ll->head == NULL) {
    ll->head = newValue;
    ll->length++;
  } else {
    newValue->next = ll->head;
    ll->head = newValue;
    ll->length++;
  }
}

char* linked_list_pop_front(linkedlist *ll)
{
  node_t *value;

  if(ll->head == NULL) {
    return NULL;
  } else {
      value = ll->head;
      ll->head = ll->head->next;

      return value->data;
  }
}

void linked_list_push_back(linkedlist *ll, char *value)
{
  node_t *current;
  node_t *newValue = malloc(sizeof(node_t));
  newValue->data = value;
  newValue->next = NULL;

  if(ll->head == NULL) {
    ll->head = newValue;
    ll->length++;
  } else {
    current = ll->head;

    while(current->next != NULL) {
      current = current->next;
    }

    current->next = newValue;
    ll->length++;
  }
}

char* linked_list_pop_back(linkedlist *ll)
{
  node_t *current;
  node_t *previous;
  node_t *value;

  if(ll->head == NULL) {
    return NULL;
  } else {
      current = ll->head;

      while(current->next != NULL) {
        previous = current;
        current = current->next;
      }

      value = current;
      previous->next = NULL;

      return value->data;
  }
}

char* linked_list_front(linkedlist *ll)
{
  if(ll->head != NULL) {
    return ll->head->data;
  }

  return NULL;
}

char* linked_list_back(linkedlist *ll)
{
  node_t *current;

  if(ll->head != NULL) {
    current = ll->head;

    while(current->next != NULL) {
      current = current->next;
    }

    return current->data;
  }

  return NULL;
}

void linked_list_insert(linkedlist *ll, int position, char *value)
{
  node_t *previous;
  node_t *current;
  node_t *newNode;
  int count = 0;

  newNode = malloc(sizeof(node_t));
  newNode->data = value;
  newNode->next = NULL;

  if(ll->head == NULL && position > 0) {
    return;
  } else if(ll->head == NULL && position == 0) {
    ll->head == newNode;
  } else {
    current = ll->head;

    while(current != NULL) {
      if(count == position) {
        previous->next = newNode;
        newNode->next = current;
        break;
      }
      previous = current;
      current = current->next;
      count++;
    }
  }
}

void linked_list_erase(linkedlist *ll, int position)
{
  node_t *current;
  node_t *previous;
  int count = 0;

  if(position == 0) {
    ll->head = ll->head->next;
  } else {
    current = ll->head;

    while(current != NULL) {
      if(count == position) {
        previous->next = current->next;
        break;
      }
      previous = current;
      current = current->next;
      count++;
    }
  }
}
