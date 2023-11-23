// Curve fitting for the dataset containing value of 1USD in INR from 2003-2023
// Data collected from www.bookmyforex.com

#include <math.h>
#include <stdio.h>

int main() {

  // Reading datapoints from DATASET.txt file
  FILE *file = fopen("DATASET.txt", "r");

  int n;
  printf("Enter the number of datapoints(n): \n");
  scanf("%d", &n);

  if (n < 2) {
    n = 2;
  } else if (n > 21) {
    n = 21;
  } else {
    n = n;
  }

  printf("Accepted value for n is %d \n\n", n);

  float x[n], y[n], y_hat[n];

  int i;
  for (i = 0; i < n; i++) {
    fscanf(file, "%f %f", &x[i], &y[i]);
  }

  fclose(file);

  float x_avg = 0, y_avg = 0, xy_avg = 0, x2_avg = 0;

  // Calculating necessery values
  for (int i = 0; i < n; i++) {
    x_avg += x[i] / n;
    y_avg += y[i] / n;
    xy_avg += (x[i] * y[i]) / n;
    x2_avg += (x[i] * x[i]) / n;
  }

  float COV = xy_avg - (x_avg * y_avg);
  float VAR = x2_avg - (x_avg * x_avg);

  float m = COV / VAR;
  float c = y_avg - (m * x_avg);

  printf("%10s%10s%10s\n", "YEAR", "INR ", "FIT ");
  printf("%10s%10s%10s\n", "----", "-----", "-----");

  for (i = 0; i < n; i++) {
    y_hat[i] = m * x[i] + c;
    printf("%10.0f%10.3f%10.3f\n", x[i], y[i], y_hat[i]);
  }

  // Equation for the straight line
  if (c > 0) {
    printf("\nThe Equation for the straight line is: \n");
    printf("%10s y = %fx + %f\n", " ", m, c);
  } else {
    printf("\nThe Equation for the straight line is: \n");
    printf("%6s y = %fx - %f\n", " ", m, -c);
  }

  // Calculating RSS value
  float RSS = 0, TSS = 0;

  for (int i = 0; i < n; i++) {
    TSS += (y[i] - y_avg) * (y[i] - y_avg);
    RSS += (y[i] - y_hat[i]) * (y[i] - y_hat[i]);
  }

  float RSqr = 1 - (RSS / TSS);
  printf("\nThe RSquare value is  %.3f\n", RSqr);

  return 0;
}
