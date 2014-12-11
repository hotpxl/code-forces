#include <stdio.h>
#include <vector>
using namespace std;

const int maxNumOfPeople = 100001;

struct Record {
  int id;
  bool goOnline;
};

struct Set {
  void clear() {
    for (int i = 0; i < maxNumOfPeople; ++i) {
      data[i] = false;
    }
    count = 0;
  }
  bool data[maxNumOfPeople];
  int count;
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<Record> records(m);
  for (int i = 0; i < m; ++i) {
    char g;
    scanf("\n%c %d", &g, &records[i].id);
    records[i].goOnline = (g == '+') ? true : false;
  }
  Set hidden, tmp;
  hidden.clear();
  hidden.count = n;
  for (int i = 1; i <= n; ++i) {
    hidden.data[i] = true;
  }
  for (int i = 0; i < m; ++i) {
    if (hidden.data[records[i].id]) {
      --hidden.count;
      hidden.data[records[i].id] = false;
    }
  }
  int xMan = 0;
  tmp.clear();
  for (int i = 0; i < m; ++i) {
    if (records[i].goOnline) {
      tmp.data[records[i].id] = true;
    } else {
      if (!tmp.data[records[i].id]) {
        xMan = records[i].id;
      }
      tmp.data[records[i].id] = false;
    }
  }
  int possible = (xMan == 0) ? records[0].id : xMan;
  tmp.clear();
  tmp.data[possible] = 1;
  tmp.count = 1;
  for (int i = 0; i < m; ++i) {
    if (records[i].goOnline) {
      if (tmp.count == 0 && records[i].id != possible) {
        possible = 0;
        break;
      }
      if (!tmp.data[records[i].id]) {
        ++tmp.count;
        tmp.data[records[i].id] = true;
      }
    } else {
      if (tmp.data[records[i].id]) {
        --tmp.count;
        tmp.data[records[i].id] = false;
      }
      if (tmp.count != 0 && records[i].id == possible) {
        possible = 0;
        break;
      }
    }
  }
  if (possible != 0) {
    hidden.data[possible] = true;
    ++hidden.count;
  }
  printf("%d\n", hidden.count);
  for (int i = 1; i <= n; ++i) {
    if (hidden.data[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}

