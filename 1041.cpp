#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long n;
int min1, min2, min3;
int dice[6];
unsigned long long ans = 0;

int main(){
	cin>>n;
	for(int i = 0; i < 6; i++){
		cin>>dice[i];
	}
	
	if(n == 1){
		int maxVal = 0;
		for(int i = 0; i < 6; i++){
			if(dice[i] > maxVal){
				maxVal = dice[i];
			}
		}
		for(int i = 0; i < 6; i++){
			ans += dice[i];
		}
		ans -= maxVal;
		cout<<ans;
		return 0;
	}
	
	min1 = min(dice[0], dice[5]);
	min2 = min(dice[1], dice[4]);
	min3 = min(dice[2], dice[3]);
	
	int one = min(min1, min(min2, min3));
	int three = min1 + min2 + min3;
	int two = three - max(min1, max(min2, min3));
	
	
	ans += (unsigned long long)(n-1)*(n-2)*one;
	ans += (unsigned long long)three;
	ans += (unsigned long long)two*(2*n - 3);
	ans = ans*4;
	ans += (unsigned long long)one*(n-2)*(n-2);
	
	cout<<ans;
	
	return 0;
}