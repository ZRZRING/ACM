#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <functional>

#define i64 long long

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 200, M = 10000;

const i64 inf = 2e9;

int n, m, S, T, cnt = 2, head[N + 10], cur[N + 10], dep[N + 10];

struct EDGE {
	int u, v, next, flow;
};

EDGE edge[M + 10];

void add(int u, int v, int t) {
	edge[cnt] = (EDGE){u, v, head[u], t}; head[u] = cnt++;
	edge[cnt] = (EDGE){v, u, head[v], 0}; head[v] = cnt++;
}

bool bfs() {
	for (int i = 1; i <= n; i++) {
		dep[i] = 0; cur[i] = head[i];
	}
	std::queue<int> q; dep[S] = 1; q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int e = head[u]; e; e = edge[e].next) {
			int v = edge[e].v, t = edge[e].flow;
			// printf("%d %d %d\n", u, v, t);
			if (!t || dep[v]) continue;
			q.push(v); dep[v] = dep[u] + 1;
		}
	}
	// for (int i = 1; i <= n; i++) printf("%d ", dep[i]); puts("");
	return dep[T];
}

i64 dfs(int u, int limit) {
	if (!limit || u == T) return limit;
	i64 res = 0;
	for (int e = cur[u]; e; e = edge[e].next) {
		int v = edge[e].v, t = edge[e].flow; cur[u] = e;
		if (dep[v] != dep[u] + 1) continue;
		t = dfs(v, std::min(limit, t));
		edge[e].flow -= t; edge[e ^ 1].flow += t; res += t; limit -= t;
		if (!limit) break;
	}
	return res;
}

void debug() {
	for (int i = 0; i < cnt; i++) {
		printf("%d %d %d %d\n", edge[i].u, edge[i].v, edge[i].next, edge[i].flow);
	}
}

int main() {
	n = read(); m = read(); S = read(); T = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), t = read(); add(u, v, t);
	}
	i64 ans = 0;
	while (bfs()) ans += dfs(S, inf);
	printf("%lld", ans);
	return 0;
}