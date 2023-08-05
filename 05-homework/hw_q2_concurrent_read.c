#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open("./dummy_file.txt", O_RDWR);
  printf("Before fork, created a fd (%d)\n", fd);

  int rc = fork();
  // Concurrent read
  if (rc < 0) {
    fprintf(stderr, "fork failed.\n");
    exit(1);
  } else if (rc == 0) {  // child  process
    char buffer[3];
    read(fd, buffer, 3);
    printf("Read a file in a child process: %s\n", buffer);

  } else {  // parent process
    char buffer[3];
    read(fd, buffer, 3);
    printf("Read a file in a parent process: %s\n", buffer);
  }
}
