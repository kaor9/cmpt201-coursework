#include <stdio.h>
#include <unistd.h>

int main() {
  int xyz = fork();
  printf("%d", xyz);
  return 0;
}
