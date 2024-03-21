#include <bits/stdc++.h>

#define endl '\n'
#define i64 long long
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

std::random_device RD;
std::mt19937_64 gen(RD());
i64 roll(i64 l, i64 r) {std::uniform_int_distribution<i64> dist(l, r); return dist(gen);}

const int mod = 1e9 + 7;

int main() {
	srand(time(0));
	int n = roll(5, 10);
	std::cout << n << endl;
	std::vector<PII> e;
	for (int i = 2; i <= n; i++) {
		e.push_back({i, roll(1, i - 1)});
	}
	std::random_shuffle(e.begin(), e.end());
	for (auto [u, v] : e) {
		std::cout << u << ' ' << v << ' ' << roll(1, 5) << endl;
	}
	int m = 10;
	std::cout << m << endl;
	for (int i = 1; i <= m; i++) {
		int t = roll(1, n - 1);
		std::cout << t << ' ';
		std::vector<int> a(n);
		std::iota(a.begin(), a.end(), 1);
		std::random_shuffle(a.begin() + 1, a.end());
		for (int j = 1; j <= t; j++) {
			std::cout << a[j] << ' ';
		}
		std::cout << endl;
	}
	return 0;
}