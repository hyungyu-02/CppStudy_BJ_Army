#include <iostream>

using namespace std;

int n, cycle;

int main(){
	cin>>n;
	int cnt = 1;
	
	//if(n < 10) n = n*10;
	cycle = n;
	int ten = cycle % 10;
	int one = ((cycle%10) + (int)cycle/10) % 10;
	cycle = ten*10 + one;
	
	while(cycle != n){
		ten = cycle % 10;
		one = ((cycle%10) + (int)cycle/10) % 10;
		cycle = ten*10 + one;
		cnt++;
	}
	cout<<cnt;
	
	return 0;
}