#include <bits/stdc++.h>

#define i64 long long

inline i64 read() {
	bool sym = 0; i64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read(), m = read();
	if (n == 1 && m == 1) {
		printf("Walk Alone"); return 0;
	}
	printf("Kelin");
	return 0;
}