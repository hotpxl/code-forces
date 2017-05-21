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
  int n, f;
  cin >> n >> f;
  vector<int> sell;
  long long int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int k, l;
    cin >> k >> l;
    cnt += min(k, l);
    sell.push_back(min(k, l - min(k, l)));
  }
  sort(sell.begin(), sell.end(), greater<int>());
  for (int i = 0; i < f; ++i) {
    cnt += sell[i];
  }
  printf("%lld\n", cnt);
  return 0;
}
