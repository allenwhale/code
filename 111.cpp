#include <stdio.h>
 
int max (int a, int b) {
  return a > b ? a : b;
}
 
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    int i, j, tmp, a[50], b[50], array[50][50];
    for (i = 1; i <= n; i++) {
      scanf("%d", &tmp);
      a[tmp] = i;
    }
    while (scanf("%d", &tmp) == 1) {
      b[tmp] = 1;
      for (i = 2; i <= n; i++) {
        scanf("%d", &tmp);
        b[tmp] = i;
      }
      for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
          array[i][j] = 0;
      for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
          if (a[i] == b[j]) array[i][j] = array[i - 1][j - 1] + 1;
          else array[i][j] = max(array[i - 1][j], array[i][j - 1]);
      printf("%d\n", array[n][n]);
    }
  }
  return 0;
}
