#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
using namespace std;

#define BUF_LEN 1048576
uint8_t* buf;
uint32_t cur, len;

void fillBuf() {
    cur = 0;
    len = fread(buf, sizeof(uint8_t), BUF_LEN, stdin);
}

void initBuf() {
    buf = (uint8_t*) calloc(BUF_LEN, sizeof(uint8_t));
    fillBuf();
}

void destroyBuf() {
    free(buf);
    buf = 0;
}

int32_t getInt() {
    int32_t ret = 0;
    int32_t sign = 1;
    while (cur < len && buf[cur] != '-' && (buf[cur] < '0' || '9' < buf[cur])) {
        if ((++cur) == len) {
            fillBuf();
        }
    }
    if (cur < len && buf[cur] == '-') {
        sign = -1;
        if ((++cur) == len) {
            fillBuf();
        }
    }
    while (cur < len && '0' <= buf[cur] && buf[cur] <= '9') {
        ret = 10 * ret + buf[cur] - '0';
        if ((++cur) == len) {
            fillBuf();
        }
    }
    return sign * ret;
}

int main() {
    initBuf();
    int n = getInt(), m = getInt();
    int mid = n / 2;
    uint64_t total = 0;
    int* criminals = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        criminals[i] = getInt();
    }
    for (int i = 0; i < mid; i += m) {
        total += criminals[mid] - criminals[i];
    }
    for (int i = n - 1; mid < i; i -= m) {
        total += criminals[i] - criminals[mid];
    }
    printf("%I64d\n", 2 * total);
    return 0;
}

