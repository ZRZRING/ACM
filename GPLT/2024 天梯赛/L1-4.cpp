#include <bits/stdc++.h>

using i64 = long long;

#define endl '\n'

int main() {
	int n, m;
	std::cin >> n >> m;
	i64 sum = 0;
	for (int i = 1; i <= m; i++) {
		i64 x = 0;
		std::cin >> x;
		sum += x;
	}
	std::cout << std::max(0ll, sum - n * (m - 1));
}
