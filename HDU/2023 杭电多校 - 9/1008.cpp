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

void write(__int128 x) {
	if (x > 9) write(x / 10);
	std::cout << char(x % 10 + '0');
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T; std::cin >> T;
	while (T--) {
		i64 n; std::cin >> n;
		__int128 sum = 0;
		std::vector<i64> a(n + 1);
		for (int i = 1; i <= n; i++) std::cin >> a[i], sum += a[i];
		__int128 ans = 0;
		for (int i = 1; i <= n; i++) ans += (sum - a[i]) * a[i];
		write(ans / 2); std::cout << endl;
	}
	return 0;
}
