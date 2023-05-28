#include <iostream>
#include <queue>

using namespace std;

int main(){
	int x;
	queue<pair<int,int>> q;
	
	cin>>x;
	q.push({x,0});
	
	while(!q.empty()){
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(n == 1){
			cout<<cnt<<endl;
			break;
		}
		
		if(n % 3 == 0) q.push({n/3,cnt+1});
		if(n % 2 == 0) q.push({n/2,cnt+1});
		q.push({n-1,cnt+1});
	}
	
	
	return 0;
}