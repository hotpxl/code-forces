#include <algorithm>
#include <cstdio>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums;
  int g = 0;
  for (int _ = 0; _ < n; ++_) {
    int in;
    cin >> in;
    g = __gcd(g, in);
    nums.push_back(in);
  }
  if (g != 1) {
    printf("YES\n0\n");
    return 0;
  }
  int odd = 0;
  int moves = 0;
  for (auto num : nums) {
    if (num % 2 == 1) {
      ++odd;
    } else {
      moves += odd / 2 + 2 * (odd % 2);
      odd = 0;
    }
  }
  moves += odd / 2 + 2 * (odd % 2);
  printf("YES\n%d\n", moves);
  return 0;
}
