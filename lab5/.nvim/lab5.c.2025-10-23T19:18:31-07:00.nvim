#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct header {
  uint64_t size;
  struct header *next;
  int id;
};

void initialize_block(struct header *block, uint64_t size, struct header *next,
                      int id) {
  block->size = size;
  block->next = next;
  block->id = id;
}

int find_first_fit(struct header *free_list_ptr, uint64_t size) {
  // TODO: Implement first fit
  while (free_list_ptr->next != NULL) {
    if (free_list_ptr->size >= size) {
      return free_list_ptr->id;
    }
    free_list_ptr = free_list_ptr->next;
  }
  return -1;
}

int find_best_fit(struct header *free_list_ptr, uint64_t size) {
  int best_fit_id = -1;
  // TODO: Implement best fit
  int best_size = UINT64_MAX;
  while (free_list_ptr->next != NULL) {
    if (free_list_ptr->size >= size && free_list_ptr->size < best_size) {
      best_size = free_list_ptr->size;
      best_fit_id = free_list_ptr->id;
    }
    free_list_ptr = free_list_ptr->next;
  }
  return best_fit_id;
}

int find_worst_fit(struct header *free_list_ptr, uint64_t size) {
  int worst_fit_id = -1;
  // TODO: Implement worst fit
  uint64_t worst_size = 0;
  while (free_list_ptr->next != NULL) {
    if (free_list_ptr->size >= size && free_list_ptr->size > worst_size) {
      worst_size = free_list_ptr->size;
      worst_fit_id = free_list_ptr->id;
    }
    free_list_ptr = free_list_ptr->next;
  }
  return worst_fit_id;
}

int main(void) {

  struct header *free_block1 = (struct header *)malloc(sizeof(struct header));
  struct header *free_block2 = (struct header *)malloc(sizeof(struct header));
  struct header *free_block3 = (struct header *)malloc(sizeof(struct header));
  struct header *free_block4 = (struct header *)malloc(sizeof(struct header));
  struct header *free_block5 = (struct header *)malloc(sizeof(struct header));

  initialize_block(free_block1, 6, free_block2, 1);
  initialize_block(free_block2, 12, free_block3, 2);
  initialize_block(free_block3, 24, free_block4, 3);
  initialize_block(free_block4, 8, free_block5, 4);
  initialize_block(free_block5, 4, NULL, 5);

  struct header *free_list_ptr = free_block1;

  int first_fit_id = find_first_fit(free_list_ptr, 7);
  int best_fit_id = find_best_fit(free_list_ptr, 7);
  int worst_fit_id = find_worst_fit(free_list_ptr, 7);

  // TODO: Print out the IDs
  printf("print out blocks:\n");
  struct header *current = free_list_ptr;
  while (current != NULL) {
    printf("block id: %d\n", current->id);
    current = current->next;
  }
  printf("first fit ID: %d\n", first_fit_id);
  printf("second fit ID: %d\n", best_fit_id);
  printf("third fit ID: %d\n", worst_fit_id);
  return 0;
}

/*
  Calculate the ptr addr adjacent to the left
  Calculate the ptr addr adjacent to right
  If(recently freed block is adjacent to left)
    increase the size of recently freed block
    Adjust the next pointer of recently freed block
    Remove curr block from the list
  If(recently freed block is adjacent to right)
    increase the size of curr block
*/
