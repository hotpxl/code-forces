#include <iostream>
#include <string>
#include <cassert>
#include <bitset>

#define S_LEN_MAX 200000

using namespace std;

int getOrdinal(char a) {
  switch (a) {
    case 'A':
      return 0;
    case 'C':
      return 1;
    case 'T':
      return 2;
    case 'G':
      return 3;
    default:
      assert(false);
  }
}

int main() {
  int sLen, tLen, errorThreshold;
  string s, t;
  cin >> sLen >> tLen >> errorThreshold >> s >> t;
  for (int i = 0; i < sLen; ++i) {
    s[i] = getOrdinal(s[i]);
  }
  for (int i = 0; i < tLen; ++i) {
    t[i] = getOrdinal(t[i]);
  }
  bitset<S_LEN_MAX> sSet[4], lSet;
  int lastSeenIndex[4];
  for (int i = 0; i < 4; ++i) {
    lastSeenIndex[i] = -(errorThreshold + 1);
  }
  for (int i = 0; i < sLen; ++i) {
    int cur = s[i];
    lastSeenIndex[cur] = i;
    for (int j = 0; j < 4; ++j) {
      if (i - lastSeenIndex[j] <= errorThreshold) {
        sSet[j][i] = 1;
      }
    }
  }
  for (int i = 0; i < 4; ++i) {
    lastSeenIndex[i] = sLen + errorThreshold;
  }
  for (int i = sLen - 1; 0 <= i; --i) {
    int cur = s[i];
    lastSeenIndex[cur] = i;
    for (int j = 0; j < 4; ++j) {
      if (lastSeenIndex[j] - i <= errorThreshold) {
        sSet[j][i] = 1;
      }
    }
  }
  lSet.flip();
  for (int i = 0; i < tLen; ++i) {
    int cur = t[i];
    lSet &= sSet[cur] >> i;
  }
  int sum = 0;
  for (int i = 0; i < sLen; ++i) {
    sum += lSet[i];
  }
  cout << sum << endl;
  return 0;
}

