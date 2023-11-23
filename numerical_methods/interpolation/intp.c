#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n; // number of datapoints to be read
  int N; // number of interpolated points

  printf("Enter number of datapoints: ");
  scanf("%d", &n);

  printf("Enter number of interpolated points: ");
  scanf("%d", &N);

  // Taking input from data.txt
  float x[n], y[n];
  FILE *file;

  file = fopen("data.txt", "r");
  if (file == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    fscanf(file, "%f %f", &x[i], &y[i]);
  }

  fclose(file);

  // Print taken data
  printf("The dataset given is: \n");
  printf("(%15s,%15s)\n", "x", "y");

  for (int i = 0; i < n; i++) {
    printf("(%15.6f,%15.6f)\n", x[i], y[i]);
  }

  //-------------------------------------
  //---Interpolation---------------------
  //-------------------------------------

  float h = (x[n - 1] - x[0]) / (N - 1);
  float X[N], Y[N];

  for (int i = 0; i < N; i++) {
    X[i] = x[0] + i * h;
    float s = 0;

    for (int j = 0; j < n; j++) {
      float u = 1, v = 1;
      for (int k = 0; k < n; k++) {
        if (k != j) {
          u = u * (X[i] - x[k]);
          v = v * (x[j] - x[k]);
        } else {
          u = 1 * u;
          v = 1 * v;
        }
      }
      s = s + (y[j] * u / v);
    }

    Y[i] = s;

    printf("(%15.6f,%15.6f)\n", X[i], Y[i]);
  }

  return 0;
}
