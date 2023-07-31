#include <iostream>
#include <string>
using namespace std;

int pieces = 0;
string str;

int main(){
	cin>>str;
	int sticksUnderMe = 0;
	for(int i = 0; i < str.size()-1; i++){
		if(str[i] == '(' && str[i+1] == '('){
			sticksUnderMe++;
		}
		else if(str[i] == '(' && str[i+1] == ')'){
			pieces += sticksUnderMe;
		}
		else if(str[i] == ')' && str[i+1] == ')'){
			pieces++;
			sticksUnderMe--;
		}
	}
	pieces += sticksUnderMe;
	cout<<pieces;
	return 0;
}