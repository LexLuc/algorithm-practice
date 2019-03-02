#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Size of short\t%lu\n", sizeof(short));
  printf("Size of int\t%lu\n", sizeof(int));
  printf("Size of long\t%lu\n", sizeof(long));
  printf("Size of long long\t%lu\n", sizeof(long long));
  printf("Size of float\t%lu\n", sizeof(float));
  printf("Size of double\t%lu\n", sizeof(double));

  return 0;
}
