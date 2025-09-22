#include <stdio.h>
#include <unistd.h>

int main() {
  fork(); // notice it says done twice at the endo fthe code since theres two
          // processes doing the same thing!
  for (int i = 0; i < 20; i++) {
    printf("Sleeping\n");
    sleep(1);
  }
  // if we were to fork here, we would get 20 sleep prints, and two dones!
  printf("DONE\n");
  return 0;
}
