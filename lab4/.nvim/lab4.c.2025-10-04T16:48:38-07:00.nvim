#define _DEFAULT_SOURCE
#define _ISOC99_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 64

struct header {
  uint64_t size;
  struct header *next;
};

void handle_error(char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

void print_out(char *format, void *data, size_t data_size) {
  char buf[BUF_SIZE];
  ssize_t len = snprintf(buf, BUF_SIZE, format,
                         data_size == sizeof(uint64_t) ? *(uint64_t *)data
                                                       : *(void **)data);

  if (len < 0) {
    handle_error("snprintf");
  }
  write(STDOUT_FILENO, buf, len);
}

void print_block(char *start) {
  for (int i = 0; i < 128; i++) {
    char *addr = (start + sizeof(struct header *) + i);
    uint64_t val = (uint64_t)*addr;
    print_out("%lu\n", &val, sizeof(val));
  }
}

int main() {
  char *heap_start = sbrk(0);
  if (sbrk(256) == (void *)-1) {
    handle_error("sbrk");
  }

  struct header *first_block = (struct header *)heap_start;
  struct header *second_block =
      (struct header *)(heap_start + 128); // each block is 128 for 256
  first_block->next = NULL;
  first_block->size = 128;
  second_block->next = first_block;
  second_block->size = 128;
  memset(first_block + 1, 0, 128 - sizeof(struct header));
  memset(second_block + 1, 1, 128 - sizeof(struct header));

  print_out("first block: %p\n", &first_block, sizeof(first_block));
  print_out("second block: %p\n", &second_block, sizeof(second_block));
  print_out("first block size: %ld\n", &first_block->size,
            sizeof(first_block->size));
  print_out("first block next: %p\n", &first_block->next,
            sizeof(first_block->next));
  print_out("second block size: %ld\n", &second_block->size,
            sizeof(second_block->size));
  print_out("second block next: %p\n", &second_block->next,
            sizeof(second_block->next));
  print_block(heap_start);
  print_block(heap_start + 128);

  return 0;
}
