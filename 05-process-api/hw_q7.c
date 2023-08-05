#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed.\n");
    exit(1);
  } else if (rc == 0) {  // child process
    close(STDOUT_FILENO);
    printf("STDOUT closed, but child likes to print something!\n");
  } else if (rc > 0) {  // parent process
    wait(NULL);         // wait for parent child to finish
    printf("Parent waited the child process finishing.\n");
  }
}
