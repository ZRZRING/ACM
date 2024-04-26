#include <bits/stdc++.h>

#define endl '\n'
#define i64 long long
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

#define rd() (rand() << 15 | rand())
#define rd64() ((1ll * rd()) << 30 | (1ll * rd()))

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int roll(int x, int y) {
	return rd() % (y - x + 1) + x;
}

i64 roll64(i64 x, i64 y) {
	return rd64() % (y - x + 1) + x;
}

int main() {
	srand(time(0));
	for (int i = 1; i <= 10; i++) {
		freopen((std::to_string(i) + ".in").c_str(), "w", stdout);
		int n = roll(4, 14), m = roll(1, std::min(90, (n * n - n) / 2));
		printf("%d %d\n", n, m);
		std::vector<int> a(n * n);
		std::iota(a.begin(), a.end(), 0);
		std::random_shuffle(a.begin(), a.end());
		for (int i = 1, j = 1; j <= m; i++, j++) {
			if (a[i] % n == a[i] / n) {j--; continue;}
			printf("%d %d %d\n", a[i] % n + 1, a[i] / n + 1, roll(1, 100));
		}
	}
	return 0;
}