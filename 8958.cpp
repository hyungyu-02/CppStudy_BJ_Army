#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string correct;
	string str = "";
	cin>>n;
	cin.ignore();
	for(int i = 0; i < n; i++){
		cin>>correct;
		int score = 0;
		int plus = 0;
		for(int j = 0; j < correct.size(); j++){
			if(correct[j] == 'X')
				plus = 0;
			else
				score += ++plus;
		}
		str += to_string(score) + "\n";
	}
	cout<<str;
	
	return 0;
}