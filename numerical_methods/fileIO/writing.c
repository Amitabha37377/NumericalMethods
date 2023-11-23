#include <stdio.h>
#include <stdlib.h>

int fn(int x) {
  int g = x * x;
  return g;
}

int main() {

  // Declare file pointer and open a file
  FILE *fptr;

  fptr = fopen("myfile.txt", "w");

  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  int n, i, j;
  char newline = '\n';

  printf("How many numbers you want to store? ");
  scanf("%d", &n);

  int nums[n];

  // Loop for writing the square of the series 1, 3, 5, ...., 2n - 1 in file
  for (i = 0; i < n; i++) {
    nums[i] = fn(2 * i + 1);

    fprintf(fptr, "%15d", 2 * i + 1);
    fprintf(fptr, "%15d", nums[i]);
    fprintf(fptr, "%15d", fn(2 * i));
    fprintf(fptr, "%s", "\n");
  }

  // Close the file
  fclose(fptr);
  return 0;
}
