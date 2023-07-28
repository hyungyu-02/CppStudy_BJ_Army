#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n;
//pair<int,int> dp[100000];
vector<pair<int,int>> dp;
int sticker[2][100000];
int colSum[100000];

int main(){
	cin>>t;
	while(t--){
		fill_n(dp,100000,0);
		fill_n(sticker[0],200000,0);
		fill_n(colSum, 100000, 0);
		dp.clear();
		cin>>n;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < n; j++){
				cin>>sticker[i][j];
				colSum[j] += sticker[i][j];
			}
		}
		
		if(sticker[0][0] >= sticker[1][0]){
			dp.push_back({sticker[0][0], 0});
		}else{
			dp.push_back({sticker[1][0], 1});
		}
		
		if(sticker[0][0] + sticker[1][1] >= sticker[1][0] + sticker[0][1]){
			dp.push_back({sticker[0][0] + sticker[1][1], 1});
		}else{
			dp.push_back({sticker[1][0] + sticker[0][1], 0});
		}
		
		for(int i = 2; i < n; i++){
			if(sticker[i][0] >= sticker[i][1]){
				dp.push_back({dp[i-2].first + sticker[i][0], 0});
			}else{
				dp.push_back({dp[i-2].first + sticker[i][1], 1});
			}
			
			if(dp[i-1].second == 0){
				
			}
		}
		
	}
	
	return 0;
}