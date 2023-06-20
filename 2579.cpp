#include <iostream>
#include <algorithm>

using namespace std;

int n;
int stairs[301];
int dp[301];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i = 1; i <= n; i++){
		cin>>stairs[i];
	}
	
	dp[0] = 0;
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	
	for(int i = 3; i <= n; i++){
		dp[i] = max(dp[i-2], dp[i-3] + stairs[i-1]);
		dp[i] += stairs[i];
	}
	
	cout<<dp[n];
	
	return 0;
}