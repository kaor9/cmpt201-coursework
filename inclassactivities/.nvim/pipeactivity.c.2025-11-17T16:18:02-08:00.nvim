#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   int    pipefd[2];
   char   buf;
   pid_t  cpid;

   if (argc != 2) {
       fprintf(stderr, "Usage: %s <string>\n", argv[0]);
       exit(EXIT_FAILURE);
   }

   if (pipe(pipefd) == -1) {
       perror("pipe");
       exit(EXIT_FAILURE);
   }

   cpid = fork();
   if (cpid == -1) {
       perror("fork");
       exit(EXIT_FAILURE);
   }
