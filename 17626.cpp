#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[50001] = {50000, };

int main(){
	cin>>n;
	dp[0] = 1;
	dp[1] = 1;
	
	for(int i = 2; i <= n; i++){
		int mini = i;
		for(int j = 1; j*j <= i; j++){
			mini = min(mini, dp[j*j] + dp[i - (j*j)]);
		}
		dp[i] = mini;
	}
	
	cout<<dp[n];
	
	return 0;
}