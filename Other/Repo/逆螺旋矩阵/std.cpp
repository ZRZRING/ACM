#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))

inline i64 read() {
    bool sym = 0;
    i64 res = 0;
    char ch = getchar();
    while (!isdigit(ch))
        sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
    int a[20][20], n;
    int p = 2;
    std::cin >> n;
    a[n / 2 + 1][n / 2 + 1] = 1;
    for (int i = n / 2; i >= 1; i--) {
        for (int j = i; j <= n - i; j++)
            a[i][j] = p++;
        for (int j = i; j <= n - i; j++)
            a[j][n - i + 1] = p++;
        for (int j = n - i + 1; j > i; j--)
            a[n - i + 1][j] = p++;
        for (int j = n - i + 1; j > i; j--)
            a[j][i] = p++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%4d", a[i][j]);
        }
        std::cout << endl;
    }
    return 0;
}