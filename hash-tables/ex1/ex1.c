#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *data = malloc(sizeof(Answer));

  // put everything in hash table.
  for (int i = 0; i<length; i++) {
    hash_table_insert(ht, weights[i], i);
  }


  for (int i = 0; i<length; i++) {
    // find a difference int and then look to see if there is an index with that difference key.
    int difference = limit - weights[i];
    int second_index = hash_table_retrieve(ht, difference);
    //if there isn't then loop through array again. 
    if (second_index != -1) {
      // if there is, we can check those indexes to see which one is the bigger index and set that one first.
      if(second_index > i) {
        data->index_1 = second_index;
        data->index_2 = i;
      } else {
        data-> index_1 = i;
        data-> index_2 = second_index;
      }
      destroy_hash_table(ht);
      return data;
    }

  }

  destroy_hash_table(ht);
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}

#endif
