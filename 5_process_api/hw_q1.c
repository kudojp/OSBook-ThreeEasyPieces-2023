#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int x = 100;
  printf("Before fork, x=%d\n", x);
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed.\n");
    exit(1);
  } else if (rc == 0) {  // child process
    printf("In a child process (%d), x=%d\n", getpid(), x);
    x = -1;
    printf("In a child process (%d), overwritten as x=%d\n", getpid(), x);
  } else {  // parent process
    printf("In a parent process (%d), x=%d\n", getpid(), x);
    x = 1;
    printf("In a parent process (%d), overwritten as x=%d\n", getpid(), x);
  }

  if (rc > 0) {  // parent process
    wait(NULL);  // wait for parent child to finish
    printf("In a parent process (%d), it turns out that x=%d\n", getpid(), x);
  }

  if (rc == 0) {  // child process
    printf("Child process is finished now.\n");
  }
}
