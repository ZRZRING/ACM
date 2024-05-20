#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define PII std::pair<i64, i64>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const i64 N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

i64 qpow(i64 a, i64 x = mod - 2) {
	i64 res = 1;
	while (x) {
		if (x & 1) res = res * a % mod; a = a * a % mod; x >>= 1;
	}
	return res;
}

int main() {
	i64 n = read(), m = n % mod;
	if (m == 2) {printf("7"); return 0;}
	printf("%lld", (mod + qpow(m, n) - m + 1) % mod);
	return 0;
}