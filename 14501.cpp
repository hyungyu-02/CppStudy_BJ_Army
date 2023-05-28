#include <iostream>
#include <algorithm>

using namespace std;

int n;
int Ti[16];
int Pi[16];
int dp[17];

int main(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>Ti[i]>>Pi[i];
	}
	// cout<<"Ti => ";
	// for(int i = 1; i <= n; i++){
	// 	cout<<Ti[i]<<" ";
	// }
	// cout<<endl;
	// cout<<"Pi => ";
	// for(int i = 1; i <= n; i++){
	// 	cout<<Pi[i]<<" ";
	// }
	// cout<<endl;
	
	for(int i = n; i > 0; i--){
		if((Ti[i] + i - 1) > n){
			dp[i] = dp[i+1];
			//cout<<"dp["<<i<<"] : "<<dp[i]<<" Ti["<<i<<"] => "<<Ti[i]<<" if문"<<endl;
			//cout<<" Ti[i] + n - 1 => "<<(Ti[i] + n - 1)<<" , n => "<<n<<endl;
		}else{
			dp[i] = max(dp[i+1], Pi[i]+ dp[i+Ti[i]]);
			//cout<<"dp["<<i<<"] : "<<dp[i]<<" else 문"<<endl;
		}
	}
	cout<<dp[1];
	return 0;
}