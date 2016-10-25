#include <cstdio>
#include <string>

struct Rec {
  bool match;
  bool prev_match;
};

bool f(std::string s, std::string p) {
  Rec** d = new Rec*[2];
  d[0] = new Rec[p.length() + 1]{};
  d[1] = new Rec[p.length() + 1]{};
  d[0][0].match = true;
  d[0][0].prev_match = true;
  for (std::size_t i = 1; i < p.length() + 1; ++i) {
    if (p[i - 1] != '*') {
      break;
    }
    d[0][i].match = true;
    d[0][i].prev_match = true;
  }
  for (std::size_t i = 1; i < s.length() + 1; ++i) {
    d[i % 2][0].match = false;
    d[i % 2][0].prev_match = true;
    for (std::size_t j = 1; j < p.length() + 1; ++j) {
      char original_char = s[i - 1];
      char pattern_char = p[j - 1];
      if (pattern_char == '*') {
        d[i % 2][j].match = d[i % 2][j - 1].prev_match;
      } else if (pattern_char == '?' || pattern_char == original_char) {
        d[i % 2][j].match = d[(i - 1) % 2][j - 1].match;
      } else {
        d[i % 2][j].match = false;
      }
      d[i % 2][j].prev_match =
          (d[i % 2][j].match || d[(i - 1) % 2][j].prev_match);
    }
  }

  bool ret = d[s.length() % 2][p.length()].match;
  delete[] d[1];
  delete[] d[0];
  delete[] d;

  return ret;
}

int main() {
  std::string a{"aaa"};
  std::string b{"*"};
  printf("%d\n", f(a, b));
}
