#include <stdio.h>
#include <stdlib.h>

int main(void) {
  while (1) {
    int d;
    scanf("%d", &d);
    if (d == -1) {
      break;
    } else if (d >= 0 && d < 45) {
      printf("N\n");
    } else if (d >= 45 && d < 90) {
      printf("NW\n");
    } else if (d >= 90 && d < 135) {
      printf("W\n");
    } else if (d >= 135 && d < 180) {
      printf("SW\n");
    } else if (d >= 180 && d < 225) {
      printf("S\n");
    } else if (d >= 225 && d < 270) {
      printf("SE\n");
    } else if (d >= 270 && d < 315) {
      printf("E\n");
    } else if (d >= 315 && d < 360) {
      printf("NE\n");
    }
  }
  return 0;
}

// N
// NW
// W
// SW
// S
// SE
// E
// NE