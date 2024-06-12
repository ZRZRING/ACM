#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		char str[250];
		int s,len,i,j,flag;

		cin>>str>>s;
		len=strlen(str);

		while(s--) {
			flag=0;
			for(i=0; i<len-1; i++) {
				if(str[i]>str[i+1]) {				
					for(j=i; j<len-1; j++)
						str[j]=str[j+1];				
					break;
				}
			}
			len--;
		}
		for(i=0;i<len;i++){
			if(str[i]!='0')
				break;
		}
		if(i==len){
			cout<<0<<endl;
			continue;
		}
		for(;i<len;i++)
			cout<<str[i];
		cout<<endl;
	}

	return 0;
}