#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("hi!\n");

  pid_t pid = fork();
  if (pid == 0) {
    printf("child\n");

    char *args[] = {"/bin/ls", "-a", "-l", "-h", NULL};
    execv("/bin/ls", args);
  } else {
    printf("parent\n");
    // first arg is the location of command ls, next arg is the location for ls,
    // third arg is -a, last must be null
    execl("/bin/ls", "/bin/ls", "-a", NULL);
  }

  printf("end\n");
  return 0;
}
