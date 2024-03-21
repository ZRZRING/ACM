#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>

#define i64 long long

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read(), m = read();
	std::vector<int> edge[n + 1];
	bool vis[n + 1] = {0};
	for (int i = 1; i <= m; i++) vis[read()] = 1;
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int dep[n + 1] = {0};
	std::function<void(int, int, int)> dfs = [&](int u, int last, int t) {
		dep[u] = dep[last] + 1;
		for (auto v : edge[u]) {
			if (v == last) continue; dfs(v, last, t);
		}
	};
	for (auto i : edge[1]) {
		dfs(i, 1, 1);
	}
	return 0;
}