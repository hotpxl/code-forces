#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  string in;
  cin >> in;
  int cnt = 0;
  for (size_t i = 0; i + 1 < in.size(); ++i) {
    if (in[i] == 'V' && in[i + 1] == 'K') {
      ++cnt;
    }
  }
  if (2 <= in.size()) {
    int s = in.size();
    if (in[0] == 'K' && in[1] == 'K') {
      ++cnt;
    } else if (in[s - 2] == 'V' && in[s - 1] == 'V') {
      ++cnt;
    } else {
      for (size_t i = 0; i + 2 < in.size(); ++i) {
        if (in[i] == in[i + 1] && in[i] == in[i + 2]) {
          ++cnt;
          break;
        }
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
