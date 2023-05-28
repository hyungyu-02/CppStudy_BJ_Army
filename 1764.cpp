//#include "header.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int BJ_1764();

int main(){
	return BJ_1764();
}


int BJ_1764(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int A, B;
	vector<string>nlisten, both;
	
	cin>>A>>B;
	
	string s;
	for(int i = 0; i < A; i++){
		cin>>s;
		nlisten.push_back(s);
	}
	sort(nlisten.begin(), nlisten.end());
	
	for(int i = 0; i < B; i++){
		cin>>s;
		if( binary_search(nlisten.begin(), nlisten.end(), s) ){
			both.push_back(s);
		}
	}
	
	sort(both.begin(),both.end());
	
	cout<<both.size()<<endl;
	for(auto o : both){
		cout<< o << endl;
	}
	
	
	return 0;
}
