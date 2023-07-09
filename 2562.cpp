#include <iostream>
using namespace std;
int maxIdx = 1;
int maxVal = 0;
int main(){
	int temp;
	for(int i = 1; i < 10; i++){
		cin>>temp;
		if(temp > maxVal){
			maxIdx = i;
			maxVal = temp;
		}
	}
	cout<<maxVal<<"\n"<<maxIdx;
	return 0;
}