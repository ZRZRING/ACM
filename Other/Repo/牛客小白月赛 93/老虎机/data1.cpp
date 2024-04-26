#include <bits/stdc++.h>

using i64 = long long;

#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<i64, i64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const i64 mod = 998244353;

std::random_device RD;
std::mt19937_64 gen(RD());
i64 roll(i64 l, i64 r) {std::uniform_int_distribution<i64> dist(l, r); return dist(gen);}

int main() {
	int T = 10000;
	std::cout << T << endl;
	while (T--) {
		std::cout << roll(1, 1e6) << ' ' << roll(1, 1e6) << ' ' << roll(1, 1e6) << ' ' << roll(1, 1e6) << endl;
	}
	return 0;
}