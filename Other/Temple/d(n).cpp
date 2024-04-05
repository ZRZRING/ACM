#include <bits/stdc++.h>

#define endl '\n'
#define i64 long long
#define PII std::pair<i64, i64>

int main() {
	int n;
    std::cin >> n;
	bool vis[n + 1];
	memset(vis, 0, sizeof(vis));
	std::vector<int> c(n + 1), d(n + 1), prime;
	vis[1] = 1;
	d[1] = 1;
	c[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            prime.push_back(i);
			c[i] = i;
			d[i] = 2;
		}
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
				c[i * prime[j]] = c[i] * prime[j];
                d[i * prime[j]] = d[i] + d[i / c[i]];
				break;
			}
			d[i * prime[j]] = d[i] * 2;
			c[i * prime[j]] = prime[j];
        }
    }
    i64 ans = 0;
    for (int i = 0; i < prime.size(); i++) {
        i64 t = n - prime[i];
        if (vis[t] == 0) continue;
		ans += d[t];
    }
    std::cout << ans;
    return 0;
}