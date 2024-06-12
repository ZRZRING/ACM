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
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		a[0] = 1;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		int k = 0, cnt = 0, flag = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == -1) {
				cnt++;
				continue;
			}
			if (k == 0) {
				for (int j = 1; j <= i - 1; j++) {
					a[j] = j % 2 == i % 2 ? a[i] : a[i] * 2;
				}
				k = i;
				continue;
			}
			int x = a[k], y = a[i], l = k + 1, r = i - 1;
			while (l <= r) {
				if (x > y) {
					if (x == 1) x *= 2;
					else x /= 2;
					a[l] = x;
					l++;
				} else {
					if (y == 1) y *= 2;
					else y /= 2;
					a[r] = y;
					r--;
				}
			}
			if (x / 2 == y || y / 2 == x) {
				k = i;
			} else {
				flag = 1;
				break;
			}
		}
		if (cnt) {
			for (int j = k + 1; j <= n; j++) {
				a[j] = (j % 2 == k % 2 ? a[k] : a[k] * 2);
			}
		}
		if (flag) {
			std::cout << -1 << endl;
		} else {
			for (int i = 1; i <= n; i++) {
				std::cout << a[i] << " \n"[i == n];
			}
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