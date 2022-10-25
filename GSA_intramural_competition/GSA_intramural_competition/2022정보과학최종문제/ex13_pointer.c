#include <stdio.h>

int main() {
  int arr[1] = { 100 };
  int* ptr = &arr[0];
  int i = 1, sum = 0;

  //arr++;
  ptr = arr + 1;
  sum += *(arr + i);
  //sum += *arr++;
  sum += (*arr)++;
}