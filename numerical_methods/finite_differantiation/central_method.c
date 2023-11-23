#include <math.h>
#include <stdio.h>

// Function for given equation
float fun(float t) {
  float pi = 3.141592;
  float val;
  float c0 = 0.497, c1 = 0.418, c2 = 0.562;

  val = c0 + c1 * cos(pi * t / 3) + c2 * sin(pi * t / 3);

  return val;
}

// Main function
int main() {
  int n, i, j;
  float h;

  printf("Enter number of steps(n): \n");
  scanf("%d", &n);

  printf("Enter the differance(h): \n");
  scanf("%f", &h);

  float time[n];
  float x[n];
  float xdot[n];
  float xddot[n];

  time[0] = 0;
  x[0] = fun(time[0]);

  for (i = 1; i < n; i++) {
    time[i] = time[i - 1] + h;
    x[i] = fun(time[i]);
  }

  printf("%15s %15s %15s %15s %15s \n", "Sl", "time(s)", "x", "xdot", "xddot");
  printf("%15d %15.6f %15.6f\n", 0, time[0], x[0]);

  for (j = 1; j < n - 1; j++) {
    xdot[j] = (x[j + 1] + x[j - 1]) / (2 * h);
    xddot[j] = (x[j + 1] - 2 * x[j] + x[j - 1]) / (h * h);

    printf("%15d %15.6f %15.6f %15.6f %15.6f \n", j, time[j], x[j], xdot[j],
           xddot[j]);
  }

  printf("%15d %15.6f %15.6f \n", n - 1, time[n - 1], x[n - 1]);

  return 0;
}
