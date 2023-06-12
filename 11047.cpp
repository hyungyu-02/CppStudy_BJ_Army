#include <iostream>

using namespace std;

int n, k;
int price[10];
int coinNum = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	
	for(int i = 0; i < n; i++){
		cin>>price[i];
	}
	
	while(k){
		int usedCoinIdx = 0;
		for(int i = 0; i < n-1; i++){
			if(price[usedCoinIdx + 1] <= k){
				usedCoinIdx++;
			}else{
				break;
			}
		}
		int nowUsed = k / price[usedCoinIdx];
		
		coinNum += nowUsed;
		
		k = k % price[usedCoinIdx];
	}
	cout<<coinNum;
	
	return 0;
}