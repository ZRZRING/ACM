#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'

int main() {
	i64 a, b;
	std::cin >> a >> b;
	std::cout << (abs(a - b) <= 1 ? "Brown" : "Alice") << endl;
	return 0;
}