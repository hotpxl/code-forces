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

int main() {
  int n;
  cin >> n;
  int last = numeric_limits<int>::max();
  bool ordered = true;
  for (int i = 0; i < n; ++i) {
    int start, end;
    cin >> start >> end;
    if (start != end) {
      printf("rated\n");
      return 0;
    }
    if (last < start) {
      ordered = false;
    }
    last = start;
  }
  if (ordered) {
    printf("maybe\n");
  } else {
    printf("unrated\n");
  }
  return 0;
}
