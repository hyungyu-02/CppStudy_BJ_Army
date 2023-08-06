#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int maxVal;
int dp[100000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	cin>>arr[0];
	dp[0] = arr[0];
	maxVal = arr[0];
	
	for(int i = 1; i < n; i++){
		cin>>arr[i];
		dp[i] = max(dp[i-1]+arr[i], arr[i]);
		maxVal = max(maxVal, dp[i]);
	}
	
	cout<<maxVal;
	
	return 0;
}