#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct {
  void **data;
  int length;
  int capacity;
} vector;

/* Initialize vector */
void vector_init(vector *);
/* Add a value to a vector */
void vector_insert(vector *, void *);
/* Delete a value at a specific index */
void vector_delete(vector *, int);
/* Return the length of a vector */
int vector_size(vector *);
/* Resize vector */
static void vector_resize(vector *, int);
/* Get capacity */
int vector_capacity(vector *);
/* Check if empty */
bool vector_empty(vector *);
/* get value at index */
void* vector_at(vector *, int);
/* Push value to end */
void vector_push(vector *, void *);
/* Insert at the beginning */
void vector_prepend(vector *, void *);
/* Get top most value */
void* vector_pop(vector *);
/* Find value and remove it */
void vector_remove(void *, void *);
/* Find item and return index */
int vector_find(void *, void *);

// size()
// capacity()
// is_empty()
// at(index)
// push(item)
// insert(index, item)
// prepend(item)
// pop()
// delete(index)
// remove(item) - looks for value and remove index holding it
// find(item) - -1 if not found
// resize(new_capacity)
