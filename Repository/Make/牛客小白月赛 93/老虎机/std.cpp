#include <bits/stdc++.h>

using i64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<i64, i64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const i64 mod = 998244353;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> i64 lg(T x) {return (int)log10(x);}
template <class T> i64 log(T x) {return (int)log2(x);}
template <class T> i64 abs(T x) {return x < 0 ? -x : x;}
template <class T> i64 mysqrt(T x) {return std::floor(sqrtl(x));}

i64 qpow(i64 a, i64 x = mod - 2) {
	a %= mod;
	i64 res = 1ll;
	while (x) {
		if (x & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		x >>= 1;
	}
	return res;
}

int solve() {
	i64 m, a, b, c;
	std::cin >> m >> a >> b >> c;
	i64 A = m * (m - 1) * (m - 2) % mod * qpow(m * m * m) % mod * a % mod;
	i64 B = (m * m * m % mod - m * (m - 1) * (m - 2) % mod + mod - m + mod) % mod * qpow(m * m * m) % mod * b;
	i64 C = qpow(m * m) * c % mod;
	std::cout << (A + B + C) % mod << endl;
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}