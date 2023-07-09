#include <iostream>
#include <string>
using namespace std;

int t, r;
string str;

int main(){
	cin>>t;
	while(t--){
		cin>>r;
		cin>>str;
		for(int i = 0; i < str.size(); i++){
			for(int j = 0; j < r; j++){
				cout<<str[i];
			}
		}
		cout<<"\n";
	}
	
	return 0;
}