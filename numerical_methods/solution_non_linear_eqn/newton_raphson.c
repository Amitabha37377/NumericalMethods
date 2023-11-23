#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float fun(float x) {
  float val = pow(x, 3) - 27;
  return val;
}

float gun(float x) {
  float val = 3 * pow(x, 2);
  return val;
}

int main() {
  float x, tol;
  int itr = 1;
  tol = 0.00001;

  printf("Initial guess: ");
  scanf("%f", &x);

  printf("%15d%15.6f%15.6f\n", itr, x, fun(x));

  while (fabs(fun(x)) > tol) {
    itr++;
    x = x - fun(x) / gun(x);
    printf("%15d%15.6f%15.6f\n", itr, x, fun(x));
  }

  printf("Solution : %.6f", x);
  return 0;
}
