#include <iostream>
#include <string>

using namespace std;

string str;
char c[100];
int numArr[50];
int numP = 0;
char oper[50];
int operP = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>c;
	
	string temp = "";
	for(int i = 0; i < 50; i++){
		if(c[i] >= '0' && c[i] <= '9'){
			temp += c[i];
		}else if(c[i] == '+' || c[i] == '-'){
			oper[operP++] = c[i];
			numArr[numP++] = stoi(temp);
			temp = "";
		}
	}
	numArr[numP++] = stoi(temp);
	
	int firstMinusOperIdx = -1;
	for(int i = 0; i < operP; i++){
		if(oper[i] == '-'){
			firstMinusOperIdx = i;
			break;
		}
	}
	
	int answer = 0;
	if(firstMinusOperIdx == -1){
		for(int i = 0; i < numP; i++){
			answer += numArr[i];
		}
		cout<<answer;
	}else{
		for(int i = 0; i <= firstMinusOperIdx; i++){
			answer += numArr[i];
		}
		for(int i = firstMinusOperIdx+1; i < numP; i++){
			answer -= numArr[i];
		}
		cout<<answer;
	}
	
	return 0;
}