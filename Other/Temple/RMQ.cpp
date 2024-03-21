#include <bits/stdc++.h>

using i64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<i64, i64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const i64 mod = 998244353;

struct RMQ {
	int n;

	std::vector<std::array<int, 30>> fmin, fmax;

	RMQ(std::vector<int> a) {
		n = a.size() - 1;
		fmin.resize(n + 1);
		fmax.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			fmin[i][0] = fmax[i][0] = a[i];
		}
		for (int i = 1; i < 30; i++) {
			if (1 << i > n) break;
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				fmin[j][i] = std::min(fmin[j][i - 1], fmin[j + (1 << i - 1)][i - 1]);
				fmax[j][i] = std::max(fmax[j][i - 1], fmax[j + (1 << i - 1)][i - 1]);
			}
		}
	}

	int max(int l, int r) {
		int k = log(r - l + 1);
		return std::max(fmax[l][k], fmax[r - (1 << k) + 1][k]);
	}

	int min(int l, int r) {
		int k = log(r - l + 1);
		return std::min(fmin[l][k], fmin[r - (1 << k) + 1][k]);
	}
};

int solve() {
	
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}