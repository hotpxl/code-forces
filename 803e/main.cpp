#include <algorithm>
#include <cinttypes>
#include <cmath>
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

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int** arr = new int* [n] {};
  for (int i = 0; i < n; ++i) {
    arr[i] = new int[2 * k + 1]{};
  }
  switch (s[0]) {
    case 'L':
      arr[0][k - 1] = 1;
      break;
    case 'D':
      arr[0][k] = 2;
      break;
    case 'W':
      arr[0][k + 1] = 3;
      break;
    default:
      arr[0][k + 1] = 3;
      arr[0][k] = 2;
      arr[0][k - 1] = 1;
      break;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < 2 * k; ++j) {
      if (arr[i - 1][j] != 0) {
        if (s[i] == 'L' || s[i] == '?') {
          arr[i][j - 1] = 1;
        }
        if (s[i] == 'D' || s[i] == '?') {
          arr[i][j] = 2;
        }
        if (s[i] == 'W' || s[i] == '?') {
          arr[i][j + 1] = 3;
        }
      }
    }
  }
  string ans;
  int i = n - 1;
  int j;
  if (arr[n - 1][0] != 0) {
    j = 0;
  } else if (arr[n - 1][2 * k] != 0) {
    j = 2 * k;
  } else {
    printf("NO\n");
    return 0;
  }
  while (0 <= i) {
    char c = '?';
    switch (arr[i][j]) {
      case 1:
        c = 'L';
        ++j;
        break;
      case 2:
        c = 'D';
        break;
      case 3:
        c = 'W';
        --j;
        break;
    }
    ans += c;
    --i;
  }
  printf("%s\n", string(ans.rbegin(), ans.rend()).c_str());

  return 0;
}
