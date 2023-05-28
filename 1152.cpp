#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string str;
	getline(cin, str);
	
	stringstream ss(str);
	int count = 0;
	while(ss>>str){
		count++;
	}
	
	cout<<count<<endl;
	
	return 0;
}