#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1001] = {0, };

int main(){
	cin>>n;
	cin>>dp[1];
	for(int i = 2; i <= n; i++){
		cin>>dp[i];
		for(int j = 1; j <= i/2; j++){
			dp[i] = max(dp[i], dp[j] + dp[i-j]);
		}
	}
	cout<<dp[n];
	
	return 0;
}