#include <iostream>
using namespace std;

long long n;
long long oilPrice[100000];
long long dist[100000];
long long totalPrice = 0;

int main(){
	cin>>n;
	for(int i = 0; i < n-1; i++){
		cin>>dist[i];
	}
	for(int i = 0; i < n; i++){
		cin>>oilPrice[i];
	}
	
	for(int i = 0; i < n-1; i++){
		//cout<<"\n now i : "<<i<<" ";
		if(oilPrice[i] >= oilPrice[i+1]){
			totalPrice += oilPrice[i] * dist[i];
		}else{
			long long cnt = 1;
			while(i+cnt+1 < n-1){
				if(oilPrice[i] < oilPrice[i+cnt+1]){
					cnt++;
				}else{
					break;
				}
			}
			for(int j = 0; j <= cnt; j++){
				totalPrice += oilPrice[i] * dist[i+j];
			}
			i += cnt;
		}
		//cout<<" and totalPrice : "<<totalPrice<<endl<<endl;
	}
	cout<<totalPrice;
	
	return 0;
}