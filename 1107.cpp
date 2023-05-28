#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

string str;
int n, m, minimum;
bool broke[10];

bool ableCh(int ch){
	string s = to_string(ch);
	for(auto i : s){
		if(broke[i-48])
			return false;
	}
	return true;
}

int main(){
	cin>>n;
	str = to_string(n);
	
	cin>>m;
	for(int i = 0; i < m; i++){
		int idx;
		cin>>idx;
		broke[idx] = true;
	}
	
	minimum = abs(n-100);
	
	for(int i = 0; i <= 1000000; i++){
		if(ableCh(i)){
			int press = abs(n-i) + to_string(i).length();
			minimum = min(minimum, press);
		}
	}
	
	cout<<minimum;
	
	return 0;
}