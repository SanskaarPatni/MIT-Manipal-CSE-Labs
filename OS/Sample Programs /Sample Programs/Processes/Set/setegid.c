#define _POSIX1_SOURCE 2
#include <unistd.h>
#include <stdio.h>

main() {
  printf("your effective group id is %d\n", (int) getegid());
  if (setegid(500) != 0)
    perror("setegid() error");
  else
    printf("your effective group id was changed to %d\n",
           (int) getegid());
}
Output

your effective group id is 512
your effective group id was changed to 500