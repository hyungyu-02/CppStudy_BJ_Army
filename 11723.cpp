#include <iostream>
#include <cstring>
#include <string>
#include <set>

using namespace std;

set<int> s;
int n;
string str;
const char* order;
int info;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	while(n--){
		cin>>str;
		order = str.c_str();
		if(!strcmp(order, "all")){
			for(int i = 1; i <= 20; i++){
				s.insert(i);
			}
		}else if(!strcmp(order, "empty")){
			s.clear();
		}else if(!strcmp(order, "add")){
			cin>>info;
			s.insert(info);
		}else if(!strcmp(order, "remove")){
			cin>>info;
			auto it = s.find(info);
			if(it != s.end()){
				s.erase(it);
			}
		}else if(!strcmp(order, "check")){
			cin>>info;
			auto it = s.find(info);
			if(it != s.end()){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
		}else{
			cin>>info;
			auto it = s.find(info);
			if(it != s.end()){
				s.erase(it);
			}else{
				s.insert(info);
			}
		}
	}
	return 0;
}