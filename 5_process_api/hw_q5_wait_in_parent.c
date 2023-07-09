#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed.\n");
    exit(1);
  } else if (rc == 0) {  // child process
    printf("Child process id is %d\n", getpid());
  } else if (rc > 0) {             // parent process
    pid_t child_pid = wait(NULL);  // wait for parent child to finish
    printf("Parent waited the child process (%d)\n", child_pid);
  }
}
