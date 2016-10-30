/* Robert Castillo */

#include<stdio.h>
#include<stdlib.h>
#include "vectors.h"

int main(void)
{
  int one = 1;
  int *one_ptr = &one;
  int two = 2;
  int *two_ptr = &two;
  int three = 3;
  int *three_ptr = &three;
  int four = 4;
  int *four_ptr = &four;
  int five = 5;
  int *five_ptr = &five;

  int i;
  vector v_string;
  vector v_int;

  vector_init(&v_string);
  vector_init(&v_int);

  // 1
  vector_add(&v_string, "one");
  vector_add(&v_int, one_ptr);
  // 2
  vector_add(&v_string, "two");
  vector_add(&v_int, two_ptr);
  // 3
  vector_add(&v_string, "three");
  vector_add(&v_int, three_ptr);
  // 4
  vector_add(&v_string, "four");
  vector_add(&v_int, four_ptr);
  // 5
  vector_add(&v_string, "five");
  vector_add(&v_int, five_ptr);

  // Same length for both vectors
  for(i = 0; i < vector_length(&v_int); i++) {
    printf("%s=%d\n", (char*)v_string.data[i], *(int*)v_int.data[i]);
  }

  vector_delete(&v_string, 0);
  vector_delete(&v_string, 0);
  vector_delete(&v_int, 0);
  vector_delete(&v_int, 0);

  for(i = 0; i < vector_length(&v_string); i++) {
    printf("%s=%d\n", (char*)v_string.data[i], *(int*)v_int.data[i]);
  }

  return 0;
}
