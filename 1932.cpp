#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int v[501][500];
int maxVal = 0;

void sumDown(int lev){
	if(lev > n){
		for(int i = 0; i < n; i++){
			maxVal = max(maxVal, v[n][i]);
		}
		return;
	}
	for(int i = 1; i < lev-1; i++){
		v[lev][i] += max(v[lev-1][i-1], v[lev-1][i]);
	}
	v[lev][0] += v[lev-1][0];
	v[lev][lev-1] += v[lev-1][lev-2];
	sumDown(lev+1);
	return;
}

int main(){
	cin>>n;
	int temp;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			cin>>v[i][j];
		}
	}
	sumDown(1);
	cout<<maxVal;
	return 0;
}