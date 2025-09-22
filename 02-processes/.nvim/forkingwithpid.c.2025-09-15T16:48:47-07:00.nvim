#include <stdio.h>
#include <unistd.h>

int main() {
  // starting pids
  printf("Start PID=%d, parent PID=%d\n", getpid(), getppid());

  // call fork
  int pid = fork();
  switch (pid) {
  case -1:
    printf("error\n");
    break;
  case 0:
    printf("CHILD: PID=%d, parent PID=%d\n", getpid(), getppid());
    break;
  default:
    printf("PARENT: PID=%d, child PID=%d\n", getpid(), pid);
  }
  return 0;
}
