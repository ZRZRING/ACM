#include <bits/stdc++.h>

using i64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<i64, i64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const i64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

int solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<PII> A(n + 1);
	#define x first
	#define y second
	for (int i = 1; i <= n; i++) {
		std::cin >> A[i].x;
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> A[i].y;
	}
	if (m >= n) {
		std::cout << 0 << endl;
		return 0;
	}
	std::sort(A.begin() + 1, A.end(), [](PII a, PII b) {
		return a.y < b.y;
	});
	i64 now = 0;
	for (int i = 1; i <= n - m; i++) {
		if (A[i].y > A[i].x) {
			now += A[i].y - A[i].x;
		}
	}
	std::priority_queue<int> q;
	for (int i = n - m + 1; i <= n; i++) {
		q.push(A[i].x);
		now -= A[i].x;
	}
	i64 ans = std::max(0ll, now);
	for (int i = n - m; i >= 1; i--) {
		if (A[i].y > A[i].x) {
			now -= A[i].y - A[i].x;
		}
		now -= A[i].x;
		q.push(A[i].x);
		now += q.top();
		q.pop();
		ans = std::max(ans, now);
	}
	std::cout << ans << endl;
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