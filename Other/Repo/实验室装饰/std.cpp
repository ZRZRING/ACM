#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;
int a[N];
int b[N];
int main()
{
    // freopen("16.in","r",stdin);
    // freopen("16.out","w",stdout);
    int n;
    int sum = 0;
    int cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++ ){
        cin >> a[i];
        if(a[i] == 1)sum ++;
        if(i == 1)continue;
        if(a[i] == 1 && a[i] == a[i - 1])cnt++;
    }
    for (int i = 1; i <= n; i ++ ){
        cin >> b[i];
        if(b[i] == 1)sum ++;
        if(i % 2 != 0 && b[i] == 1 && a[i] == b[i]) cnt++;
        if(i == 1)continue;
        if(b[i] == 1 && b[i] == b[i - 1])cnt++;
    }
    cout << sum * 3 - cnt * 2;
}