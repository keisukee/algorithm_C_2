#include <stdio.h>

int main(void) {
  int i, j, k, n;
  int item_number = 7;

  int prices[8];
  prices[0] = 0;
  prices[1] = 120;
  prices[2] = 360;
  prices[3] = 600;
  prices[4] = 960;
  prices[5] = 1600;
  prices[6] = 3000;
  prices[7] = 5000;

  int counts[8];
  counts[0] = 0;
  counts[1] = 1;
  counts[2] = 5;
  counts[3] = 9;
  counts[4] = 15;
  counts[5] = 25;
  counts[6] = 50;
  counts[7] = 86;


  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int drinks;
    scanf("%d", &drinks);

    int dp[item_number+1][drinks+1]; // dp[アイテムの番号][本数] = 値段の合計

    for (k = 0; k <= drinks; k++) dp[0][k] = 0;
    for (k = 0; k <= drinks; k++) dp[1][k] = 120 * k;

    for (j = 2; j <= item_number; j++) {
      for (k = 0; k <= drinks; k++) {
        if (k < counts[j]) {
          // printf("k = %d, count = %d\n", k, counts[j]);
          dp[j][k] = dp[j-1][k];
        } else {
          int min = dp[j-1][k - counts[j]] + prices[j];
          if (min > dp[j-1][k])
            min = dp[j-1][k];
          else if (min > dp[j][k - counts[j]] + prices[j])
            min = dp[j][k - counts[j]] + prices[j];
          // if (dp[j-1][k] >= dp[j-1][k - counts[j]] + prices[j])
          //   min = dp[j-1][k - counts[j]] + prices[j];
          // else
          //   min = dp[j-1][k];
          // printf("min = %d\n", min);
          dp[j][k] = min;
        }
      }
    }

    // for (j = 0; j <= item_number; j++) {
    //   for (k = 0; k <= drinks; k++) {
    //     printf("%d |", dp[j][k]);
    //   }
    //   printf("\n");
    // }
    // printf("\n");
    printf("%d\n", dp[item_number][drinks]);
  }

}