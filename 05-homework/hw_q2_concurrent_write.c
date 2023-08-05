#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open("./dummy_file2.txt", O_RDWR);
  printf("Before fork, created a fd (%d)\n", fd);

  int rc = fork();
  // Concurrent write
  if (rc == 0) {  // child  process
    for (int i = 0; i < 3; i++) {
      char buffer[] = "Write from child process\n";
      write(fd, buffer, sizeof(buffer));
      sleep(1);
    }
  } else {  // parent process
    for (int i = 0; i < 3; i++) {
      char buffer[] = "Write from parent process\n";
      write(fd, buffer, sizeof(buffer));
      sleep(1);
    }
  }
}
