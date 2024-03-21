#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define PII std::pair<i64, i64>

const i64 mod = 998244353;

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        i64 n;
        std::cin >> n;
        std::queue<PII> q;
        std::map<i64, i64> mp;
        q.push({n, 0});
        while (!q.empty()) {
            PII x = q.front(); q.pop();
            if (mp.find(x.first) != mp.end()) continue;
            mp[x.first] = x.second;
            if (x.first == 0) {
                printf("%lld\n", x.second);
                break;
            }
            q.push({x.first - 1, x.second + 1});
            if (x.first % 2 == 0) {
                q.push({x.first / 2, x.second + 1});
            }
            if (x.first % 3 == 0) {
                q.push({x.first / 3, x.second + 1});
            }
        }
    }
    return 0;
}