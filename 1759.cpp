#include <iostream>
#include <string>
#include <set>

using namespace std;

int l, c;
set<char> aei;
set<char> bcd;


int main(){
	cin>>l>>c;
	char temp;
	for(int i = 0; i < c; i++){
		cin>>temp;
		if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'){
			aei.insert(temp);
		}else{
			bcd.insert(temp);
		}
	}
	
	for(int i = 1; l-i >= 2; i++){
		
	}
	return 0;
}