#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string in;
  cin >> in;
  int cnt = 0;
  for (size_t i = 0; i < in.size() / 2; ++i) {
    auto j = in.size() - i - 1;
    if (in[i] != in[j]) {
      ++cnt;
    }
  }
  if (cnt == 1) {
    printf("YES\n");
  } else if (cnt == 0 && in.size() % 2 == 1) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
