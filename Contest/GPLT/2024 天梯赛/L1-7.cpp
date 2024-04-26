#include <bits/stdc++.h>

using i64 = long long;

#define endl '\n'

int main() {
	int L, R;
	std::cin >> L >> R;
	std::vector<i64> ans;
	auto check = [&](auto self, i64 x) -> i64 {
		i64 res = 1;
		while (x) {
			res *= x % 10;
			x /= 10;
		}
		if (res >= 10) return self(self, res) + 1;
		else return 1;
	};
	i64 res = -1;
	for (int i = L; i <= R; i++) {
		int t = check(check, i);
		if (i < 10) t = 0;
		if (t > res) {
			res = t;
			ans.clear();
		}
		if (t == res) {
			ans.push_back(i);
		}
	}
	std::cout << res << endl;
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << " \n"[i == ans.size() - 1];
	}
}
