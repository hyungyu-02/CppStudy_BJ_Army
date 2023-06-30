#include <iostream>

using namespace std;

int t, n;
long long dp[101] = {0,1,1,1,2,2};
int point = 6;

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		if(n < point){
			cout<<dp[n]<<"\n";
		}else{
			for(;point <= n; point++){
				dp[point] = dp[point-5] + dp[point-1];
			}
			cout<<dp[n]<<"\n";
		}
	}
}