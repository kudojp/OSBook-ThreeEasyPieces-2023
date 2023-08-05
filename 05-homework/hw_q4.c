#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed.\n");
    exit(1);
  } else if (rc == 0) {  // child process
    // Please uncomment aside from one.

    execl("/usr/local/bin/tree", NULL);

    // Can path environment variables.
    execle("/usr/local/bin/tree", "var1=x", NULL);

    // Can specify PATH.
    execlp("tree", "/usr/local/bin:/usr/bin", NULL);

    // Can path command arguments in a form of vector.
    execv("/usr/local/bin/tree", (char *[]){"tree", "-if", NULL});

    // NOTE: I don't know how I can path PATH.
    execvp("tree", (char *[]){"tree", "-if", NULL});

    execvpe("/usr/local/bin/tree", (char *[]){"tree", "-if", NULL},
            (char *[]){"tree", "-if", NULL});
  }
}
