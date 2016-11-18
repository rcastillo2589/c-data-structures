#include "vectors.h"

void vector_init(vector *v)
{
  v->data = (void**)malloc(sizeof(void*) * INITIAL_CAPACITY);
  v->capacity = INITIAL_CAPACITY;
  v->length = 0;
}

void vector_insert(vector *v, void *value)
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

int vector_size(vector *v)
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

int vector_capacity(vector *v)
{
  return v->capacity;
}

int vector_empty(vector *v)
{
  if(v->length == 0) {
    return 1;
  }

  return 0;
}

void* vector_at(vector *v, int at)
{
  if(v->length != 0) {
    return v->data[at];
  }

  return NULL;
}

void vector_push(vector *v, void *value)
{
  if(v->length == v->capacity) {
    vector_resize(v, v->capacity * 2);
  }

  v->data[v->length++] = value;
}

void vector_prepend(vector *v, void *value)
{
  int i;
  void *temp;

  if(v->length == v->capacity) {
    vector_resize(v, v->capacity * 2);
  }

  temp = v->data[0];

  for(i = v->length; i > 0; i--) {
    v->data[i] = v->data[i - 1];
  }

  v->data[0] = value;
  v->length++;
}

void* vector_pop(vector *v)
{
  void *value;

  if(v->length != 0) {
    value = v->data[v->length - 1];
    v->data[v->length - 1] = NULL;
    v->length--;

    if(v->length == v->capacity / 4) {
      vector_resize(v, v->capacity / 2);
    }

    return value;
  }

  return NULL;
}

void vector_remove(vector *v, void *value)
{
  int i;

  if(v->length != 0 && value != NULL) {
    for(i = 0; i < v->length -1; i++) {
      if(v->data[i] == value) {
        v->data[i] == NULL;
      }
    }

    for(; i < v->length - 1; i++) {
      v->data[i] = v->data[i + 1];
    }

    v->length--;
  }
}

int vector_find(vector *v, void *value)
{
  int i;

  if(v->length != 0) {
    for(i = 0; i < v->length - 1; i++) {
      if(v->data[i] == value) {
        return i;
      }
    }
  }

  return -1;
}
