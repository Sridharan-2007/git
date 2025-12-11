#include <stdio.h>
int add(int a, int b) {
  return a + b;
}
int main() {
  int (*ptr)(int, int) = add;
  int result = ptr(5, 3);
  printf("Result: %d", result);
  return 0;
}
    