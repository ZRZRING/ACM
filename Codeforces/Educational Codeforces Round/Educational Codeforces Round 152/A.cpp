#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define PII std::pair<int, int>

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read() + read();
		printf("%d\n", std::min(n - 1, m) * 2 + 1);
	}
	return 0;
}