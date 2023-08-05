#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fork_child();

int main(int argc, char *argv[]) {
  fork_child();
  fork_child();
  fork_child();
}

void fork_child() {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed.\n");
    exit(1);
  } else if (rc == 0) {  // child process
    sleep(1);
    printf("Child process (%d) finished.\n", getpid());
    exit(0);
  } else if (rc > 0) {  // parent process
    int child_pid = rc;
    waitpid(child_pid, NULL, 0);
  }
}
