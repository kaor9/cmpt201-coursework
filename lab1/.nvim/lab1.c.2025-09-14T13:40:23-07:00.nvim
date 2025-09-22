#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *input = NULL;
  size_t len = 0;

  printf("Please enter some text: ");
  if (getline(&input, &len, stdin) != -1) {
    char *saveptr;
    char *ret = strtok_r(input, " ", &saveptr);

    // keep printing until strtok_r returns null
    while (ret != NULL) {
      printf("%s\n", ret);
      ret = strtok_r(NULL, " ", &saveptr);
    }

    free(input);
  } else {
    printf("Error on reading text. Closing program");
  }

  return 0;
}
