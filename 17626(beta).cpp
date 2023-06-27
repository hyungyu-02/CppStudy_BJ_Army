#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n;
vector<int> v;

int findMin(int num, int count){
	if(num <= 3){
		return count + num;
	}
	int highest = sqrt(num);
	int down = highest;
	vector<int> cases;
	
	while(true){
		if(down*down*2 >= highest*highest){
			cases.push_back(down);
		}else{
			break;
		}
		down--;
	}
	
	int minCnt = 50000;
	for(int i = 0; i < cases.size(); i++){
		minCnt = min(minCnt, findMin(num - pow(cases[i],2), count+1));
	}
	return minCnt;
}

int main(){
	cin>>n;
	
	cout<<findMin(n, 0);
	
	return 0;
}