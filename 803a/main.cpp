#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

int matrix[128][128];

int main() {
  int n;
  int k;
  cin >> n >> k;
  if (n * n < k) {
    printf("-1\n");
    return 0;
  }
  memset(matrix, 0, sizeof(matrix));
  int i = 0;
  int j = 0;
  while (0 < k) {
    if (matrix[i][j] == 0) {
      if (i == j) {
        matrix[i][j] = 1;
        --k;
      } else {
        if (2 <= k) {
          matrix[i][j] = 1;
          matrix[j][i] = 1;
          k -= 2;
        }
      }
    }
    ++j;
    if (j == n) {
      ++i;
      j = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
