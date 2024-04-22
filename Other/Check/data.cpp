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
	std::vector<int> id(n);
	std::vector<std::vector<int>> e(n);
	std::iota(id.begin(), id.end(), 0);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int x = roll(0, 2);
			if (!x) {
				e[id[i]].push_back(id[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << e[i].size() << ' ';
		for (auto x : e[i]) {
			std::cout << x << ' ';
		}
		std::cout << endl;
	}
	return 0;
}