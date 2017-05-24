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
  string orig, vic;
  cin >> orig >> vic;
  if (orig.size() < vic.size()) {
    printf("0\n");
    return 0;
  }
  int* prefix = new int[vic.size()]{};
  {
    size_t i = 0;
    for (size_t j = 1; j < vic.size(); ++j) {
      while (i != 0 && vic[i] != vic[j]) {
        i = prefix[i - 1];
      }
      if (vic[i] == vic[j]) {
        ++i;
      }
      prefix[j] = i;
    }
  }
  int** jump_table = new int*[vic.size() + 1]{};
  {
    for (size_t i = 0; i < vic.size() + 1; ++i) {
      jump_table[i] = new int[26]{};
    }
    for (size_t i = 0; i < vic.size(); ++i) {
      for (int j = 0; j < 26; ++j) {
        char c = 'a' + j;
        int cur_state = i;
        while (cur_state != 0 && c != vic[cur_state]) {
          cur_state = prefix[cur_state - 1];
        }
        if (c == vic[cur_state]) {
          jump_table[i][j] = cur_state + 1;
        } else {
          jump_table[i][j] = 0;
        }
      }
    }
    for (int j = 0; j < 26; ++j) {
      char c = 'a' + j;
      int cur_state = vic.size();
      cur_state = prefix[cur_state - 1];
      while (cur_state != 0 && c != vic[cur_state]) {
        cur_state = prefix[cur_state - 1];
      }
      if (c == vic[cur_state]) {
        jump_table[vic.size()][j] = cur_state + 1;
      } else {
        jump_table[vic.size()][j] = 0;
      }
    }
  }
  int** dp = new int*[orig.size()]{};
  {
    for (size_t i = 0; i < orig.size(); ++i) {
      dp[i] = new int[vic.size() + 1]{};
      for (size_t j = 0; j < vic.size() + 1; ++j) {
        dp[i][j] = -1;
      }
    }
    if (orig[0] == '?') {
      for (char c = 'a'; c <= 'z'; ++c) {
        int next_state = jump_table[0][c - 'a'];
        int cnt = 0;
        if (next_state == static_cast<int>(vic.size())) {
          ++cnt;
        }
        dp[0][next_state] = cnt;
      }
    } else {
      char c = orig[0];
      int next_state = jump_table[0][c - 'a'];
      int cnt = 0;
      if (next_state == static_cast<int>(vic.size())) {
        ++cnt;
      }
      dp[0][next_state] = cnt;
    }
    for (size_t i = 0; i + 1 < orig.size(); ++i) {
      for (size_t j = 0; j < vic.size() + 1; ++j) {
        if (dp[i][j] == -1) {
          continue;
        }
        if (orig[i + 1] == '?') {
          for (char c = 'a'; c <= 'z'; ++c) {
            int next_state = jump_table[j][c - 'a'];
            int cnt = dp[i][j];
            if (next_state == static_cast<int>(vic.size())) {
              ++cnt;
            }
            dp[i + 1][next_state] = max(dp[i + 1][next_state], cnt);
          }
        } else {
          char c = orig[i + 1];
          int next_state = jump_table[j][c - 'a'];
          int cnt = dp[i][j];
          if (next_state == static_cast<int>(vic.size())) {
            ++cnt;
          }
          dp[i + 1][next_state] = max(dp[i + 1][next_state], cnt);
        }
      }
    }
  }
  int m = 0;
  for (size_t j = 0; j < vic.size() + 1; ++j) {
    for (size_t i = 0; i < orig.size(); ++i) {
      m = max(dp[i][j], m);
    }
  }
  printf("%d\n", m);
  return 0;
}
