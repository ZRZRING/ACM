#include <bits/stdc++.h>

using i64 = long long;

#define endl '\n'
#define PII std::pair<i64, i64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const i64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

struct WORK {
	int n, m;

	std::vector<i64> inv;

	i64 qpow(i64 a, i64 x = mod - 2) {
		a %= mod;
		x %= mod - 1;
		i64 res = 1;
		while (x) {
			if (x & 1) res = res * a % mod;
			a = a * a % mod;
			x >>= 1;
		}
		return res;
	}

	WORK() {
		n = 2e5;
		inv.resize(n + 1);
		inv[0] = inv[1] = 1;
		for (int i = 2; i <= n; i++) {
			inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		}
	}

	void solve() {
		int n, k;
		std::cin >> n >> k;
		std::vector<i64> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		auto lowbit = [&](int x) -> int {
			return x & -x;	
		};
		for (int i = 1; i <= n; i++) {
			i64 mul = 1;
			for (int j = i + lowbit(i), d = 1; j <= n; j += lowbit(j), d++) {
				mul = mul * (d + k - 1) % mod * inv[d] % mod;
				MOD(a[j] -= mul * a[i] % mod);
			}
		}
		for (int i = 1; i <= n; i++) {
			std::cout << a[i] << " \n"[i == n];
		}
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}