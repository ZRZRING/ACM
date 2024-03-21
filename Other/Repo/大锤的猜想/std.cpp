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

long long gcd(int a, int b) {if (!b) return a; return gcd(b, a % b);}

long long C(int m, int n) {
	long long res = 1;
	for (int i = m + 1; i <= n; i++) res *= i;
	for (int i = 1; i <= n - m; i++) res /= i;
	return res;
}

int main() {
	int n = read(), m = read(), sex = read(), x = read(), y = read();
	if (!sex) x = y; long long a = C(x, n), b = 0;
	for (int i = m; i <= n; i++) b += C(i, n);
	long long d = gcd(a, b);
	if (b == d) printf("%lld", a / d); else printf("%lld/%lld", a / d, b / d);
	return 0;
}