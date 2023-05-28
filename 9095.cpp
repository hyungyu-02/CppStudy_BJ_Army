#include <iostream>

using namespace std;

int t, n;
int arr[11];
int endPoint = 4;

int main(){
	cin>>t;
	
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	
	for(int i = 0; i < t; i++){
		cin>>n;
		if(n >= endPoint){
			for(int j = endPoint; j <= n; j++){
				arr[j] = arr[j-1] + arr[j-2] + arr[j-3];
				endPoint++;
			}
		}
		cout<<arr[n]<<"\n";
	}
	
	return 0;
}