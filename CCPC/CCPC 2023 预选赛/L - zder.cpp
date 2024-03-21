#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'

i64 read() {
	i64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read();
	i64 a[n + 1], b[n + 1];

	std::pair<i64, i64> data[n + 1];
	for (int i = 1; i <= n; i++) {
		data[i] = {read(), read()};
	}

	std::sort(data + 1, data + n + 1, [](std::pair<i64, i64> a, std::pair<i64, i64> b) {
		if (a.first + a.second == b.first + b.second) {
			return a.first == b.first ? a.second < b.second : a.first < b.first;
		} else {
			return a.first + a.second < b.first + b.second;
		}
	});
	for (int i = 1; i <= n; i++) a[i] = data[i].first, b[i] = data[i].second;
	// for (int i = 1; i <= n; i++) printf("%d %d\n", a[i], b[i]);
	
	i64 sum = 0, max = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i]; max = std::max(max, b[i]);
		printf("%lld\n", sum + max);
	}

	return 0;
}