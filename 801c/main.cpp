#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n;
  int p;
  cin >> n >> p;
  vector<pair<int, int>> devices;
  for (int _ = 0; _ < n; ++_) {
    int a;
    int b;
    cin >> a >> b;
    devices.push_back(make_pair(a, b));
  }
  double total =
      accumulate(devices.begin(), devices.end(), 0.0,
                 [](double acc, auto&& i) -> double { return acc + i.first; });
  if (total <= p) {
    printf("-1\n");
    return 0;
  }
  double l = 0.0;
  double r = 1e10;
  while (1e-8 < r - l) {
    double need = 0;
    double m = (l + r) / 2;
    for (auto&& d : devices) {
      need += max(d.first * m - d.second, 0.0);
    }
    if (p * m < need) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%f\n", l);
  return 0;
}
