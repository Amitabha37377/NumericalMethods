#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float fun(float x) {
  float val = pow(x, 3) - 27;
  return val;
}
int main() {
  float f, a, b, x0, x1, x, f1, f0, tol;
  int itr = 1;
  tol = 0.00001;

  printf("Enter a: ");
  scanf("%f", &a);

  printf("Enter b: ");
  scanf("%f", &b);

  if (fun(a) * fun(b) >= 0) {
    printf("Wrong value for a, b \n");
    return 1;
  }

  x0 = a;
  x1 = b;

  printf("%15s%15s%15s%15s%15s\n", "itr", "x0", "x1", "x", "f(x)");

  while (fabs(fun(x)) > tol) {
    f1 = fun(x1);
    f0 = fun(x0);
    x = x0 - (x0 - x1) * f0 / (f0 - f1);
    printf("%15d%15.6f%15.6f%15.6f%15.6f \n", itr, x0, x1, x, fun(x));

    f = fun(x);

    if (f * f1 < 0) {
      x0 = x;
    } else {
      x1 = x;
    }
    itr++;
  }
  printf("\nSoution for the given eqn is: %.6f\n", x);

  return 0;
}
