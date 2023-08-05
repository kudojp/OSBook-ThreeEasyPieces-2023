#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_goodbye();

int main(int argc, char* argv[]) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed.\n");
    exit(1);
  } else if (rc == 0) {  // child process
    printf("hello from child process.\n");
    kill(getppid(), SIGUSR1);
  } else {  // parent process
    signal(SIGUSR1, print_goodbye);
    pause();
  }
}

void print_goodbye() { printf("goodbye from parent process\n"); }

// Below does not work because fork() creates a new process, not a new thread in
// the same process.

// int main(int argc, char *argv[]) {
//   bool *child_done = (bool *)malloc(sizeof(bool));
//   *child_done = false;

//   int rc = fork();
//   if (rc < 0) {
//     fprintf(stderr, "fork failed.\n");
//     exit(1);
//   } else if (rc == 0) {  // child  process
//     printf("hello from child\n");
//     *child_done = true;
//   } else {  // parent process
//     while (*child_done == false) {
//     }
//     printf("goodbye from parent\n");
//   }
// }
