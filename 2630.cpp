#include <iostream>

using namespace std;

int n;
int paper[128][128];
int blue = 0;
int white = 0;

bool single(int r, int c, int d){
	int first = paper[r][c];
	for(int i = 0; i < d; i++){
		for(int j = 0; j < d; j++){
			if(!(first == paper[r+i][c+j])){
				return false;
			}
		}
	}
	if(first == 1){
		blue++;
	}else{
		white++;
	}
	return true;
}

void cut(int r, int c, int d){
	if(d == 1){
		if(paper[r][c])
			blue++;
		else
			white++;
		return;
	}
	if(single(r,c,d))
		return;
	cut(r,c,(d/2));
	cut(r,c+(d/2),(d/2));
	cut(r+(d/2),c,(d/2));
	cut(r+(d/2),c+(d/2),(d/2));
	return;
}

int main(){
	cin>>n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>paper[i][j];
		}
	}
	
	cut(0,0,n);
	
	cout<<white<<"\n"<<blue;
	
	return 0;
}