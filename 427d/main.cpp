#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_LEN 8192

int mat[MAX_LEN][MAX_LEN];

void repeatingSubString(char* s, int* ret) {
    memset(mat, 0, sizeof(mat));
    int len = strlen(s);
    memset(ret, 0, MAX_LEN * sizeof(int));
    for (int i = 1; i < len; ++i) {
        if (s[i] == s[0]) {
            mat[0][i] = 1;
            ret[i] = 1;
            ret[0] = 1;
        }
    }
    for (int i = 1; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (s[i] == s[j]) {
                mat[i][j] = mat[i - 1][j - 1] + 1;
                if (ret[i] < mat[i][j]) {
                    ret[i] = mat[i][j];
                }
                if (ret[j] < mat[i][j]) {
                    ret[j] = mat[i][j];
                }
            }
        }
    }
}

int commonSubString(char* s1, int* r1, char* s2, int* r2) {
    int ret = MAX_LEN;
    memset(mat, 0, sizeof(mat));
    int len1 = strlen(s1), len2 = strlen(s2);
    for (int i = 0; i < len1; ++i) {
        if (s1[i] == s2[0]) {
            mat[0][i] = 1;
            if (r1[i] < 1 && r2[0] < 1) {
                ret = 1;
            }
        }
    }
    for (int i = 0; i < len2; ++i) {
        if (s1[0] == s2[i]) {
            mat[i][0] = 1;
            if (r1[0] < 1 && r2[i] < 1) {
                ret = 1;
            }
        }
    }
    if (ret == 1) {
        return ret;
    }
    for (int i = 1; i < len2; ++i) {
        for (int j = 1; j < len1; ++j) {
            if (s1[j] == s2[i]) {
                int cur = mat[i - 1][j - 1] + 1;
                mat[i][j] = cur;
                if (r1[j] < cur && r2[i] < cur) {
                    int newMin = ((r1[j] < r2[i]) ? r2[i] : r1[j]) + 1;
                    if (newMin < ret) {
                        ret = newMin;
                    }
                }
            }
        }
    }
    if (ret == MAX_LEN) {
        return -1;
    }
    return ret;
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    int r1[MAX_LEN], r2[MAX_LEN];
    int len1, len2;
    fgets(s1, MAX_LEN, stdin);
    fgets(s2, MAX_LEN, stdin);
    len1 = strlen(s1);
    len2 = strlen(s2);
    if (s1[len1 - 1] == '\n') {
        s1[len1 - 1] = '\0';
    }
    if (s2[len2 - 1] == '\n') {
        s2[len2 - 1] = '\0';
    }
    repeatingSubString(s1, r1);
    repeatingSubString(s2, r2);
    printf("%d\n", commonSubString(s1, r1, s2, r2));
}

