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

int main() {
  int n;
  cin >> n;
  int* arr = new int[n]{};
  int* dis = new int[n]{};
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    dis[i] = numeric_limits<int>::max();
  }
  int cur = n;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 0) {
      cur = 0;
    }
    dis[i] = min(dis[i], cur);
    ++cur;
  }
  cur = n;
  for (int i = n - 1; 0 <= i; --i) {
    if (arr[i] == 0) {
      cur = 0;
    }
    dis[i] = min(dis[i], cur);
    ++cur;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", dis[i]);
  }
  printf("\n");
  return 0;
}
