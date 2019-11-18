#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Point;

int main(void) {
  int i, j, d;
  int n, m, p;
  scanf("%d", &d);

  for (i = 0; i < d; i++) {
    int points;
    scanf("%d", &points);

    Point list[100];
    for (j = 0; j < 100; j++) {
      list[i].x = 0;
      list[i].y = 0;
    }

    for (j = 0; j < points; j++) {
      scanf("%d %d", &list[j].x, &list[j].y);
    }

    double a, b; // y = ax + b
    int max_point_count = 0;
    int x_dif, y_dif;
    for (n = 0; n < points; n++) {
      for (m = 0; m < points && n != m; m++) {
        int point_count = 0;
        for (p = 0; p < points; p++) {
          if ( (list[m].x - list[n].x) * (list[p].y - list[n].y) == (list[m].y - list[n].y) * (list[p].x - list[n].x) ) {
            point_count++;
          }

        }
        if (point_count > max_point_count) max_point_count = point_count;
      }
    }

    printf("%d\n", max_point_count);
  }
  return 0;
}
