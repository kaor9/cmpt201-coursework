// server

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <sys/un.h>


int main() {
  printf("SERVER:\n");

  // socket
  // our use, protocol is always 0
  int socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("Socket failed!");
    exit(EXIT_FAILURE);
  }

  // bind
 struct sockaddr_un sockstruct;
  sockstruct.sun_family = AF_UNIX;
  snprintf(sockstruct.sun_path, 108, "socket_fun");
 if (bind(socket_fd, ) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  // listen
  // accept
  // read
  // close

  

  return 0;
}
