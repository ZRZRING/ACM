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
		i64 p, a, b, q, c, d, m, T;
		std::cin >> p >> a >> b;
		std::cin >> q >> c >> d;
		std::cin >> m >> T;
		while (T) {
			i64 x = m / p;
			if (x <= 0) break;
			if ((q - p) * x >= p) break;
			i64 r = std::max(1ll, ((x + 1) * p - m) / ((q - p) * x));
			i64 s = (q - p) * x;
			i64 t = (a + c) * x + b + d;
			s *= std::min(T / t, r);
			t *= std::min(T / t, r);
			if (t <= 0) break;
			// std::cout << x << ' ' << r << ' ' << s << ' ' << t << endl;
			m += s;
			T -= t;
		}
		while (T) {
			i64 x = std::min(m / p, (T - b - d) / (a + c));
			if (x <= 0) break;
			i64 s = (q - p) * x;
			i64 t = ((a + c) * x + b + d);
			if (t > T) break;
			// std::cout << x << ' ' << s << ' ' << t << endl;
			m += s;
			T -= t;
		}
		std::cout << m << endl;
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