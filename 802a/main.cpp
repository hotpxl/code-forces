#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  string x;
  string y;
  cin >> x >> y;
  for (size_t i = 0; i < x.size(); ++i) {
    if (x[i] < y[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << y << endl;
  return 0;
}
