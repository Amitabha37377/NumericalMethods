#include <stdio.h>

// Function to perform linear interpolation
double interpolate(double x1, double y1, double x2, double y2, double x) {
  return y1 + (x - x1) * (y2 - y1) / (x2 - x1);
}

int main() {
  FILE *file;
  char filename[100];
  double x[100], y[100], interpolatedX[100], interpolatedY[100];
  int numPoints, numInterpolatedPoints;

  // Input the file name
  printf("Enter the file name: ");
  scanf("%s", filename);

  // Input the number of points
  printf("Enter the number of points: ");
  scanf("%d", &numPoints);

  // Input the x, y points from the file
  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }

  for (int i = 0; i < numPoints; i++) {
    fscanf(file, "%lf %lf", &x[i], &y[i]);
  }

  fclose(file);

  // Input the number of interpolated points
  printf("Enter the number of interpolated points: ");
  scanf("%d", &numInterpolatedPoints);

  // Perform linear interpolation
  double step = (x[numPoints - 1] - x[0]) / (numInterpolatedPoints - 1);

  for (int i = 0; i < numInterpolatedPoints; i++) {
    interpolatedX[i] = x[0] + i * step;

    // Find the interval for interpolation
    int j = 0;
    while (interpolatedX[i] > x[j + 1]) {
      j++;
    }

    // Perform linear interpolation
    interpolatedY[i] =
        interpolate(x[j], y[j], x[j + 1], y[j + 1], interpolatedX[i]);
  }

  // Display the interpolated points
  printf("\nInterpolated Points:\n");
  for (int i = 0; i < numInterpolatedPoints; i++) {
    printf("%.2lf %.2lf\n", interpolatedX[i], interpolatedY[i]);
  }

  return 0;
}
