#include "vectors.h"

void vector_init(vector *v)
{
  v->data = (void**)malloc(sizeof(void*) * INITIAL_CAPACITY);
  v->capacity = INITIAL_CAPACITY;
  v->length = 0;
}

void vector_add(vector *v, void *value)
{
  if(v->length == v->capacity) {
    vector_resize(v, v->capacity * 2);
  }

  v->data[v->length++] = value;
}

void vector_delete(vector *v, int position)
{
  int i;
  void *temp;

  if(v->length == 0 || position > v->length) {
    return;
  }

  v->data[position] = NULL;

  for(i = position; i < v->length - 1; i++) {
    v->data[i] = v->data[i + 1];
  }

  v->data[v->length - 1] = NULL;
  v->length--;

  if(v->length == v->capacity / 4) {
    vector_resize(v, v->capacity / 2);
  }
}

int vector_length(vector *v)
{
  return v->length;
}

static void vector_resize(vector *v, int capacity)
{
  void **data = (void**)realloc(v->data, sizeof(void*) * capacity);
  if(data) {
    v->data = data;
  }
  v->capacity = capacity;
}
