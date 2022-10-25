#include <stdio.h>
#include <conio.h>
#include <math.h>

void main() {
  int i;
  double a, b;
  double X[] = { 0.84, 0.95, 1.40, 1.55, 1.19, 1.75, 1.45, 1.97, 1.50 };
  double Y[] = { 0.60, 0.62, 0.64, 0.66, 0.68, 0.70, 0.72, 0.74, 0.76 };
  double lr = 0.01;

  a = 0.1;
  b = 0.0;
  double delta_a, delta_b;
  int n = 0;
  double previous_error = 9999.0;

  while (1) {
    delta_a = 0;
    delta_b = 0;
    for (i = 0; i < 9; i++) {
      double y;
      y = a * X[i] + b;
      delta_a += (Y[i] - y) * X[i];
      delta_b += (Y[i] - y);
    }
    a = a + lr * delta_a;
    b = b + lr * delta_b;

    double error;
    error = 0.0;
    for (i = 0; i < 9; i++) {
      double d;
      d = pow((Y[i] - a * X[i] - b), 2);
      error += d;
    }
    error = error / 9.0;
    n++;
    printf("%d\t %1.6f\t %1.2f\t %1.2f\n", n, error, a, b);
    if ((previous_error - error) < 0.000001)
      break;
    previous_error = error;
  }
}