#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> fa;
    int n;
    DSU(int _n = 0) : n(_n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            fa[x] = y;
        }
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, ans = 0;
        cin >> n;
        DSU dsu(n);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dsu.merge(i, a[i]);
        }
        vector<bool> vis(n + 1);
        for (int i = 1; i <= n; i++) {
            int x = dsu.find(i);
            if (vis[x] == true) {
                continue;
            }
            vis[x] = true;
            ans += 1;
        }
        cout << n - ans << "\n";
    }
    return 0;
}