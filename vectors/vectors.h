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
void vector_add(vector *, void *);
/* Delete a value at a specific index */
void vector_delete(vector *, int);
/* Return the length of a vector */
int vector_length(vector *);
/* Resize vector */
static void vector_resize(vector *, int);
