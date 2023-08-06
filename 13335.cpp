#include <iostream>
#include <vector>
using namespace std;

int n, w, l;
int trucks[1000];
int pnt = 0;
int sec = 0;
//vector<pair<int,int>> tt;
int bridge[100];

int tw(){
	int totalW = 0;
	for(int i = 1; i < w; i++){
		totalW += bridge[i];
	}
	return totalW;
}
void passing(){
	for(int i = 1; i < w; i++){
		bridge[i-1] = bridge[i];
	}
	bridge[w-1] = 0;
	return;
}

int main(){
	cin>>n>>w>>l;
	fill_n(bridge, w, 0);
	for(int i = 0; i < n; i++){
		cin>>trucks[i];
	}
	while(pnt < n){
		if(tw() + trucks[pnt] <= l){
			passing();
			bridge[w-1] = trucks[pnt++];
		}else{
			passing();
		}
		sec++;
	}
	sec += w;
	cout<<sec;
	return 0;
}