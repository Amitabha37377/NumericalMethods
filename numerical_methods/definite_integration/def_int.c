#include <math.h>
#include <stdio.h>

// Function for given equation
float fun(float t) {
  return (pow(t, 3) * (-2.0 / 6) + pow(t, 2) * (1) + t * 6 + 100);
}

int main() {

  float a, b, h;
  int n;

  printf("Enter the lower limit: \n");
  scanf("%f", &a);

  printf("Enter the upper limit: \n");
  scanf("%f", &b);

  printf("Enter the number of divisions(n): \n");
  scanf("%d", &n);

  if (n % 2 != 0) {
    n++;
  }
  printf("The value of n is taken as %d\n", n);

  printf("Which method to use? \n");
  printf("  (1) Trapezoidal Meth;od \n");
  printf("  (2) Simpson Method \n");

  int method;
  scanf("%d", &method);

  h = (b - a) / n;

  if (method == 1) {
    float s = 0;
    float x;
    int i;

    for (i = 1; i < n; i++) {
      x = a + (i * h);
      s = s + fun(x);
    }

    float s2 = fun(a) + fun(b);
    float result = (h / 2) * (s2 + 2 * s);

    printf("Definite Integral = %f \n", result);
  }

  else if (method == 2) {
    float s1 = 0, s2 = 0, s3 = 0;
    int i, j;

    float x;

    for (i = 2; i < n; i += 2) {
      x = a + (i * h);
      s2 = s2 + fun(x);
    }

    for (j = 1; j < n; j += 2) {
      x = a + (j * h);
      s3 = s3 + fun(x);
    }

    s1 = fun(a) + fun(b);

    float result = (h / 3) * (s1 + 2 * s2 + 4 * s3);
    printf("Definite Integral = %f \n", result);
  }

  else {
    printf("Enter a valid method number \n");
  }

  return 0;
}
