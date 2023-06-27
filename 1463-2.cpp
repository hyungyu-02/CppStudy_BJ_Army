#include <iostream>
#include <algorithm>

using namespace std;

int x;
int dp[1000001];

int main(){
	cin>>x;
	
	dp[1] = 0;
	dp[2] = 1;
	
	for(int i = 3; i <= x; i++){
		if(i % 2 == 0 && i % 3 == 0){
			dp[i] = min(1 + dp[i-1], min(1 + dp[i/2], 1 + dp[i/3]));
		}else if(i % 3 == 0){
			dp[i] = min(1 + dp[i-1], 1 + dp[i/3]);
		}else if(i % 2 == 0){
			dp[i] = min(1 + dp[i-1], 1 + dp[i/2]);
		}else{
			dp[i] = 1 + dp[i-1];
		}
	}
	
	cout<<dp[x];
	
	return 0;
}