#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

#define i64 long long

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int mod = 1e9 + 7;

i64 qpow(i64 a, i64 x) {
	i64 res = 1;
	while (x) {
		if (x & 1) res = res * a % mod; a = a * a % mod; x >>= 1;
	}
	return res;
}

int main() {
	int T = read();
	while (T--) {
		i64 n = read(), m = read();
		printf("%lld\n", qpow(qpow(2, m) - 2, n));
	}
	return 0;
}