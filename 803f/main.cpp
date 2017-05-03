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

constexpr int static modulo = 1000000000 + 7;

unsigned long long quickpow(unsigned long long m, unsigned long long n) {
  unsigned long long b = 1;
  m = m % modulo;
  while (0 < n) {
    if (n & 1) {
      b = (b * m) % modulo;
    }
    n = n >> 1;
    m = (m * m) % modulo;
  }
  return b;
}

int main() {
  int n;
  cin >> n;
  int* nums = new int[n];
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  int max_num = numeric_limits<int>::min();
  for (int i = 0; i < n; ++i) {
    max_num = max(max_num, nums[i]);
  }
  int* gcds = new int[max_num + 1]();
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j * j < nums[i]; ++j) {
      if (nums[i] % j == 0) {
        ++gcds[j];
        ++gcds[nums[i] / j];
      }
    }
    int j = sqrt(nums[i]);
    if (j * j == nums[i]) {
      ++gcds[j];
    }
  }
  for (int i = 1; i < max_num + 1; ++i) {
    gcds[i] = (quickpow(2, gcds[i]) - 1 + modulo) % modulo;
  }
  for (int i = max_num; 0 < i; --i) {
    for (int j = 2; j * i <= max_num; ++j) {
      gcds[i] = (gcds[i] - gcds[j * i] + modulo) % modulo;
    }
  }
  printf("%d\n", gcds[1]);
  return 0;
}
