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

int split(vector<int> const& s, int len) {
  int cum = 0;
  int cnt = 0;
  for (auto i : s) {
    cum += i;
    if (len < cum) {
      ++cnt;
      cum = i;
    }
  }
  if (cum != 0) {
    ++cnt;
  }
  return cnt;
}

int main() {
  int k;
  cin >> k;
  string s;
  getline(cin, s);
  getline(cin, s);
  vector<int> ss;
  int last = -1;
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    if (s[i] == ' ' || s[i] == '-') {
      ss.push_back(i - last);
      last = i;
    }
  }
  ss.push_back(static_cast<int>(s.size()) - last - 1);
  int l = *max_element(ss.begin(), ss.end());
  int r = 1000000;
  while (l <= r) {
    int mid = (l + r) / 2;
    int kk = split(ss, mid);
    if (kk <= k) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", l);
  return 0;
}
