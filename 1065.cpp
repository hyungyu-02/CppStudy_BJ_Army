#include <iostream>

using namespace std;

int n;
int cnt = 0;

int main(){
	cin>>n;
	if(n<100){
		cout<<n;
		return 0;
	}
	cnt += 99;
	for(int i = 1; i <= (n/100); i++){
		for(int d = ((int)(i/2))*(-1); d <= (int)(9 - i)/2; d += 1){
			int hundred = i;
			int ten = hundred + d;
			int one = ten + d;
			if(n < hundred*100 + ten*10 + one){
				cout<<cnt;
				return 0;
			}
			//cout<<(hundred*100 + ten*10 + one)<<endl;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}