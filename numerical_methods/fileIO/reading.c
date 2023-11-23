#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *fptr;
  fptr = fopen("myfile2.txt", "r");

  if (fptr == NULL) {
    printf("No file found");
    exit(1);
  }

  int numbers[29];
  int num, i;

  for (i = 0; i < 29; i++) {
    fscanf(fptr, "%d", &num);
    numbers[i] = num;
  }

  for (i = 0; i < 29; i++) {
    printf("%d \n", numbers[i]);
  }

  return 0;
}
