#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int sol[100000];
int neut = 2000000000;
int bestPair[2];

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>sol[i];
	}
	
	if(sol[0] >= 0){
		cout<<sol[0]<<" "<<sol[1];
		return 0;
	}
	if(sol[n-1] <= 0){
		cout<<sol[n-2]<<" "<<sol[n-1];
		return 0;
	}
	
	int left = 0;
	int right = n-1;
	while(left < right){
		int sum = sol[left] + sol[right];
		if(abs(sum) < neut){
			neut = abs(sum);
			bestPair[0] = left;
			bestPair[1] = right;
		}
		
		if(sum < 0)
			left++;
		else
			right--;
	}
	
	cout<<sol[bestPair[0]]<<" "<<sol[bestPair[1]];
	
	
	return 0;
}