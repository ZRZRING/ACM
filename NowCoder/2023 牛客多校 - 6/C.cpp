#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	i64 n = read(), ans = 0;
	std::vector<i64> f(20, 0); f[0] = 1;
	for (int i = 1; pow(10, i) <= n; i++) {
		f[i] = (9ll * (f[i - 1] + i) + 2ll) % mod;
		ans = (ans + f[i]) % mod;
	}
	for (int i = 0; n; n /= 10) {
		int t = n % 10;
		if (i) ans = (ans + (t - 1) * f[i - 1] % mod) % mod;
		if (t >= 5) t++;
	}
	return 0;
}