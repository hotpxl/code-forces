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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> souvenirs;
  for (int i = 0; i < n; ++i) {
    int w, c;
    cin >> w >> c;
    souvenirs.push_back(make_pair(w, c));
  }
  sort(souvenirs.begin(), souvenirs.end(), [](auto const& a, auto const& b) {
    return static_cast<double>(a.first) / a.second <
           static_cast<double>(b.first) / b.second;
  });
  long long int* cost = new long long int[m + 9]{};
  int mm = 0;
  for (int i = 0; i < n; ++i) {
    int w = souvenirs[i].first;
    int c = souvenirs[i].second;
    for (int j = mm; max(0, mm - 10) <= j; --j) {
      cost[j + w] = max(cost[j + w], cost[j] + c);
    }
    mm = min(mm + w, m);
  }
  long long int ma = 0;
  for (int i = 0; i <= m; ++i) {
    ma = max(ma, cost[i]);
  }
  printf("%lld\n", ma);
  return 0;
}
