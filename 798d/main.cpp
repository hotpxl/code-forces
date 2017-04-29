#include <algorithm>
#include <cstdio>
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
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    a.push_back(in);
  }
  for (int i = 0; i < n; ++i) {
    int in;
    cin >> in;
    b.push_back(in);
  }
  vector<tuple<int, int, int>> nums;
  for (int i = 0; i < n; ++i) {
    nums.emplace_back(make_tuple(a[i], b[i], i + 1));
  }
  sort(nums.rbegin(), nums.rend());
  printf("%d\n%d", n / 2 + 1, get<2>(nums[0]));
  for (int i = 0; i < (n - 1) / 2; ++i) {
    auto index = i * 2 + 1;
    if (get<1>(nums[index]) < get<1>(nums[index + 1])) {
      printf(" %d", get<2>(nums[index + 1]));
    } else {
      printf(" %d", get<2>(nums[index]));
    }
  }
  if (n % 2 == 0) {
    printf(" %d", get<2>(nums.back()));
  }
  printf("\n");
  return 0;
}
