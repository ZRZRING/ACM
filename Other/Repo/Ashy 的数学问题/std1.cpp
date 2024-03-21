#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int a[N];
int cnt2 = 0,cnt5 = 0;
int main()
{
	int n, m;
	cin >> n >> m;
	bool flag = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(a[i] == 0){
			flag = 1;
		}
	}
	if(flag){
		cout << "1";
		return 0;
	}
	for(int i = 0;i < n;i++){
		int aa = a[i];
		while(aa % 2 == 0){
			aa /= 2;
			cnt2++;
		}
		while(aa % 5 == 0){
			aa /= 5;
			cnt5++;
		}
	}
	cout << min(cnt2,cnt5);
}
