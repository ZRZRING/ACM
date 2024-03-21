#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

void solve() {
	int n = read();
	std::priority_queue<int> q;
	std::vector<int> vis(200);
	for (int i = 1; i <= n; i++) vis[read()] ^= 1;
	for (int i = 1; i <= 100; i++) if (vis[i]) q.push(i);
	while (q.size() > 1) {
		int x = q.top(); q.pop(); int y = q.top(); q.pop();
		if (x - y) q.push(x - y);
	}
	if (q.empty()) printf("0\n"); else printf("%d\n", q.top());
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}