#include <iostream>
using namespace std;

long long a, b, c;

long long power(int u){
	if(u == 0) return 1;
	if(u == 1) return a % c;
	long long num = power(u/2) % c;
	if(u % 2 == 0) return num * num % c;
	return num % c * num % c * a % c;
}
int main(){
	cin>>a>>b>>c;
	
	cout<<power(b);
	return 0;
}