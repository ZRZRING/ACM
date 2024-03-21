#include <bits/stdc++.h>

#define i64 long long

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read(), k = read(), a[n + 1];
		for (int i = 1; i <= n; i++) a[i] = read();
		int cnt = 0; i64 ans = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] > k) {cnt = 0; continue;}
			cnt++; ans += std::max(0, cnt - m + 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}