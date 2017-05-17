#include <algorithm>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> as;
  set<long long int> sums;
  sums.insert(0);
  long long int total = 0;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    as.push_back(tmp);
    total += tmp;
    sums.insert(total);
  }
  long long int all = total;
  if (all % 2 == 1) {
    printf("NO\n");
    return 0;
  }
  all /= 2;
  total = 0;
  for (int i = 0; i < n; ++i) {
    long long int cur = as[i];
    total += cur;
    if (sums.count(all + cur) != 0 && total <= all + cur) {
      printf("YES\n");
      return 0;
    }
    if (sums.count(all - cur) != 0 && all - cur < total) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
