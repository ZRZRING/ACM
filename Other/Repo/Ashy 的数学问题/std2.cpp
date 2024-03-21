#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
#define int long long
int primes[N];

void get_primes(int x)
{
	for (int i = 2; i <= x / i; i++)
		while (x % i == 0)
		{
			x /= i;
			primes[i]++;
		}

	if (x > 1)
		primes[x]++;
}

void solve()
{
	int flag = 0; 
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if(x == 0){
			flag = 1;
		}
		get_primes(x);
	}
	if(flag){
		cout << "1";
		return;
	}
	int ans = 1e9;
	int x = m;
	for (int i = 2; i <= x / i; i++)
	{
		int cnt = 0;
		while (x % i == 0)
		{
			x /= i;
			cnt ++;
		}
		if(cnt != 0)
			ans = min(ans, primes[i] / cnt);
	}

	if (x > 1)
		ans = min(ans, primes[x]);
	cout << ans << "\n";

}
signed main()
{
//	freopen("2.in","r",stdin);
//	freopen("2.out","w",stdout);
//	cin.tie(0);
//	cout.tie(0);
//	ios::sync_with_stdio(0);
	int T = 1;
	// cin >> T;
	while (T--)
	{
		solve();
	}
}

