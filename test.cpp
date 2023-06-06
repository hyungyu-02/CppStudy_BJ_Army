#include <string>
#include <iostream>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	set<pair<int,int>> s;
	s.insert({100,100});
	s.insert({100,10});
	s.insert({50,100});
	s.insert({50,10});
	s.insert({10,1000});
	
	for(auto it = s.begin(); it != s.end(); it++){
		pair<int,int> p = *(it);
		cout<<p.first<<" "<<p.second<<endl;
	}
	
	
	//string str = "test";
	//cout<<str[1]<<endl;
	//if(str[0] == 't')
	//	cout<<"char";
	// if(str[0] == "t"){
	// 	cout<<"string";
	// }
	// string str = "1234";
	// int a = str[1];//2 so -48
	// cout<<a;
	return 0;
}