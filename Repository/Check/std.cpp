#include <bits/stdc++.h>

using i64 = long long;

#define endl '\n'
#define PII std::pair<i64, i64>
#define NO return (void)(std::cout << "NO" << endl)
#define YES return (void)(std::cout << "YES" << endl)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const i64 mod = 998244353;

template <class T> void MOD(T &x) {x = (x % mod + mod) % mod;}
template <class T> T lg(T x) {return (T)log10(x);}
template <class T> T log(T x) {return (T)log2(x);}
template <class T> T abs(T x) {return x < 0 ? -x : x;}
template <class T> T mysqrt(T x) {return std::floor(sqrtl(x));}

struct WORK {
    int N;

    WORK() {}

    void solve() {
        int n;
        std::cin >> n;
        std::vector<int> val(n + 1);
        for (int i = 1; i <= n; i++) {
            std::cin >> val[i];
        }
        std::vector<std::vector<int>> e(n + 1);
        for (int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int ans = 0;
        auto dfs = [&](auto self, int u, int last) -> int {
            for (auto v : e[u]) {
                if (v == last) continue;
                if (val[v] * 2 < val[u]) return 0;
                if (!self(self, v, u)) return 0;
            }
            return 1;
        };
        for (int i = 1; i <= n; i++) {
            if (dfs(dfs, i, 0)) ans++;
        }
        std::cout << ans << endl;
    }
};

int main() {
    Fast_IOS;
    WORK work;
    int T = 1;
    std::cin >> T;
    while (T--) {
        work.solve();
    }
    return 0;
}