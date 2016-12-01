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
  int six = 6;
  int *six_ptr = &six;
  int seven = 7;
  int *seven_ptr = &seven;
  int zero = 0;
  int *zero_ptr = &zero;

  int i;
  vector v_string;
  vector v_int;

  vector_init(&v_string);
  vector_init(&v_int);

  printf("IsEmpty: %s\n", vector_empty(&v_string) ? "true" : "false");
  printf("Capacity: %d\n", vector_capacity(&v_string));

  // 1
  vector_insert(&v_string, "one");
  vector_insert(&v_int, one_ptr);
  // 2
  vector_insert(&v_string, "two");
  vector_insert(&v_int, two_ptr);
  // 3
  vector_insert(&v_string, "three");
  vector_insert(&v_int, three_ptr);
  // 4
  vector_insert(&v_string, "four");
  vector_insert(&v_int, four_ptr);
  // 5
  vector_insert(&v_string, "five");
  vector_insert(&v_int, five_ptr);

  printf("Capacity: %d\n", vector_capacity(&v_string));

  printf("Insert 1 - 5\n");
  printf("(Loop start)\n");
  // Same length for both vectors
  for(i = 0; i < vector_size(&v_int); i++) {
    printf("%s=%d\n", (char*)vector_at(&v_string, i), *(int*)vector_at(&v_int, i));
  }
  printf("(Loop end)\n\n");

  vector_delete(&v_string, 0);
  vector_delete(&v_string, 0);
  vector_delete(&v_int, 0);
  vector_delete(&v_int, 0);

  printf("Delete position 0 2x\n");
  printf("(Loop start)\n");
  for(i = 0; i < vector_size(&v_string); i++) {
    printf("%s=%d\n", (char*)vector_at(&v_string, i), *(int*)vector_at(&v_int, i));
  }
  printf("(Loop end)\n\n");

  vector_push(&v_string, "six");
  vector_push(&v_int, six_ptr);
  vector_push(&v_string, "seven");
  vector_push(&v_int, seven_ptr);
  vector_prepend(&v_string, "zero");
  vector_prepend(&v_int, zero_ptr);

  printf("Push 6 & 7 Prepend 0\n");
  printf("(Loop start)\n");
  for(i = 0; i < vector_size(&v_string); i++) {
    printf("%s=%d\n", (char*)vector_at(&v_string, i), *(int*)vector_at(&v_int, i));
  }
  printf("(Loop end)\n\n");

  printf("%s=%d\n", (char*)vector_pop(&v_string), *(int*)vector_pop(&v_int));
  printf("%s=%d\n", (char*)vector_pop(&v_string), *(int*)vector_pop(&v_int));

  printf("Pop 2x\n");
  printf("(Loop start)\n");
  for(i = 0; i < vector_size(&v_string); i++) {
    printf("%s=%d\n", (char*)vector_at(&v_string, i), *(int*)vector_at(&v_int, i));
  }
  printf("(Loop end)\n\n");

  return 0;
}
