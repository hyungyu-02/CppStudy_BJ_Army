#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
int sticker0[100000];
int sticker1[100000];
int dp0[100000];
int dp1[100000];

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>sticker0[i];
		}
		for(int i = 0; i < n; i++){
			cin>>sticker1[i];
		}
		
		dp0[0] = sticker0[0];
		dp1[0] = sticker1[0];
		dp0[1] = sticker1[0] + sticker0[1];
		dp1[1] = sticker0[0] + sticker1[1];
		
		for(int i = 2; i < n; i++){
			dp0[i] = sticker0[i] + max(dp1[i-1], dp1[i-2]);
			dp1[i] = sticker1[i] + max(dp0[i-1], dp0[i-2]);
		}
		
		if(dp0[n-1] >= dp1[n-1])
			cout<<dp0[n-1]<<"\n";
		else
			cout<<dp1[n-1]<<"\n";
	}
	
	return 0;
}