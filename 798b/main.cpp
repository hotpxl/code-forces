#include <algorithm>
#include <cstdio>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int rotate(string const& target, string const& str) {
  string tmp = str + str;
  size_t size = target.size();
  for (size_t i = 0; i < size; ++i) {
    if (tmp.substr(i, size) == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<string> strs;
  for (int _ = 0; _ < n; ++_) {
    string in;
    cin >> in;
    strs.push_back(in);
  }
  int moves = numeric_limits<int>::max();
  auto str_len = strs[0].size();
  string target = strs[0] + strs[0];
  for (size_t i = 0; i < str_len; ++i) {
    int cum = 0;
    string real_target = target.substr(i, str_len);
    for (auto&& j : strs) {
      auto r = rotate(real_target, j);
      if (r == -1) {
        printf("-1\n");
        return 0;
      }
      cum += r;
    }
    moves = min(cum, moves);
  }
  printf("%d\n", moves);
  return 0;
}
