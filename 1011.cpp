//#include "header.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

#define MAX_1697 100001

int BJ_1764();int BJ_1000();int BJ_1051();int BJ_1697();int BJ_1011();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); //cin과 cout의 속도를 높여줌
	
	return BJ_1011();
}


int BJ_1011(){
	int t;
	cin>>t;
	queue<pair<int,int>> q;
	
	for(int i = 0; i < t; i++){
		int a, b;
		cin>>a>>b;
		int root = sqrt(b-a);
		q.push({root, b-a-pow(root,2)});
	}
	
	while(!q.empty()){
		int root = q.front().first;
		int d = q.front().second;
		q.pop();
		if(d == 0)
			cout<<(2*root - 1)<<endl;
		else if(d <= root)
			cout<<(2*root)<<endl;
		else
			cout<<(2*root + 1)<<endl;
	}
	
	return 0;
}