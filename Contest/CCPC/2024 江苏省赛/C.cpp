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
	int N;

	WORK() {}

	void solve() {
		int n, A = 0, B = 0, x = 0, y = 0, t;
		std::cin >> n;
		std::cout << "? " << x + 1 << endl;
		std::cout.flush();
		std::cin >> t;
		A = t;
		B = n - A;
		for (int i = 29; i >= 0; i--) {
			y = (x + (1 << i)) % n;
			std::cout << "? " << y + 1 << endl;
			std::cout.flush();
			std::cin >> t;
			if (t != A) continue;
			x = y;
		}
		if (A < B) {
			y = (x - A + n) % n;
			std::cout << "! " << x + 1 << ' ' << y + 1 << endl;
		} else {
			x = (x + 1) % n;
			y = (x + B) % n;
			std::cout << "! " << x + 1 << ' ' << y + 1 << endl;
		}
		std::cout.flush();
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