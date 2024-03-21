#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin>>n;
		int x,y;
		x=(n+56)%10;//╪в 
		y=(n+56)%12;//вс 
		cout<<char('A'+x)<<char('a'+y)<<" "; 
		if(n%400==0||(n%4==0&&n%100!=0)){
			cout<<"Yes"<<'\n';
		}else{
			cout<<"No"<<'\n';
		}
	} 
	return 0;
}
