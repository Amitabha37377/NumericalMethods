#include <math.h>
#include <stdio.h>

// Declare g and l
const double g = 9.81;
double l;

// Define d2x/dt2 function
double d2xdt2(double x) {
  double val = -(g / l) * sin(x);
  return val;
}

int main() {

  // Declare necessery variables
  double h, tend, release_angle_degrees;

  // Take inputs
  printf("Enter the length of pendulum (l): \n");
  scanf("%lf", &l);

  printf("Enter the step size (h): \n");
  scanf("%lf", &h);

  printf("Enter the duration: \n");
  scanf("%lf", &tend);

  printf("Enter the release angle in degrees: \n");
  scanf("%lf", &release_angle_degrees);

  // Convert degrees to radian
  double release_angle = release_angle_degrees * M_PI / 180;

  // Initial variables
  double t = 0.00;
  double x_el[2] = {release_angle, 0.0};
  double x_me[2] = {release_angle, 0.0};
  double x_rk2[2] = {release_angle, 0.0};
  double x_rk4[2] = {release_angle, 0.0};
  double k[2][4];

  // First row
  printf("%10s%10s%10s%10s%10s\n", "t", "x_el", "x_me", "x_rk2", "x_rk4");
  printf("%10.3f%10.3f%10.3f%10.3f%10.3f\n", t, x_el[0] * 180.0 / M_PI,
         x_me[0] * 180.0 / M_PI, x_rk2[0] * 180.0 / M_PI,
         x_rk4[0] * 180.0 / M_PI);

  t = t + h;

  while (t <= tend) {
    // Forward Euler Method
    k[0][0] = h * (x_el[1]);
    k[1][0] = h * d2xdt2(x_el[0]);

    x_el[0] += k[0][0];
    x_el[1] += k[1][0];

    // Modified Euler Method
    k[0][0] = h * (x_me[1]);
    k[1][0] = h * d2xdt2(x_me[0]);
    k[0][1] = h * (x_me[1] + 0.5 * k[1][0]);
    k[1][1] = h * d2xdt2(x_me[0] + 0.5 * k[0][0]);

    x_me[0] += k[0][1];
    x_me[1] += k[1][1];

    // Second Order Runga Kutta Method
    k[0][0] = h * (x_rk2[1]);
    k[1][0] = h * d2xdt2(x_rk2[0]);
    k[0][1] = h * (x_rk2[1] + k[1][0]);
    k[1][1] = h * d2xdt2(x_rk2[0] + k[0][0]);

    x_rk2[0] += (k[0][0] + k[0][1]) / 2.0;
    x_rk2[1] += (k[1][0] + k[1][1]) / 2.0;

    // Fourth Order Runga Kutta
    k[0][0] = h * (x_rk4[1]);
    k[1][0] = h * d2xdt2(x_rk4[0]);
    k[0][1] = h * (x_rk4[1] + k[1][0] * 0.5);
    k[1][1] = h * d2xdt2(x_rk4[0] + k[0][0] * 0.5);
    k[0][2] = h * (x_rk4[1] + k[1][1] * 0.5);
    k[1][2] = h * d2xdt2(x_rk4[0] + k[0][1] * 0.5);
    k[0][3] = h * (x_rk4[1] + k[1][2]);
    k[1][3] = h * d2xdt2(x_rk4[0] + k[0][2]);

    x_rk4[0] += (k[0][0] + 2.0 * k[0][1] + 2.0 * k[0][2] + k[0][3]) / 6.0;
    x_rk4[1] += (k[1][0] + 2.0 * k[1][1] + 2.0 * k[1][2] + k[1][3]) / 6.0;

    printf("%10.3f%10.3f%10.3f%10.3f%10.3f\n", t, x_el[0] * 180.0 / M_PI,
           x_me[0] * 180.0 / M_PI, x_rk2[0] * 180.0 / M_PI,
           x_rk4[0] * 180.0 / M_PI);
    t += h;
  }

  return 0;
}
