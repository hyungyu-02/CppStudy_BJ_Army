#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int maxVal = -1000;
int temp[100000];

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		temp[i] = arr[i];
		maxVal = max(maxVal, arr[i]);
	}
	
	for(int l = 2; l <= n; l++){
		for(int i = 0; i+l-1 < n; i++){
			temp[i] = temp[i] + arr[i+l-1];
			maxVal = max(maxVal, temp[i]);
		}
	}
	
	cout<<maxVal;
	
	return 0;
}