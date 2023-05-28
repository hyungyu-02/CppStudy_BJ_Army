#include <iostream>

using namespace std;

int n;
int col[15];
int total = 0;

bool check(int colomn){
	for(int i = 0; i < colomn; i++){
		if(col[i] == col[colomn]){
			return false;
		}
		if(colomn-i == abs(col[i] - col[colomn])){
			return false;
		}
	}
	return true;
}

void nQueen(int lev){
	if(lev == n){
		total++;
		return;
	}
	
	for(int j = 0; j < n; j++){
		col[lev] = j;
		if(check(lev)){
			nQueen(lev+1);
		}
	}
}

int main(){
	cin>>n;
	nQueen(0);
	cout<<total;
	return 0;
}