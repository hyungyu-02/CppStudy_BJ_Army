#include <iostream>
#include <queue>

#define MAX_1697 100001

using namespace std;


int main(){
	int n, k, result;
	bool visit[MAX_1697] = {false};
	queue<pair<int,int>> q;
	
	cin>>n>>k;
	
	q.push({n,0});
	visit[n] = true;
	
	//bfs
	while(!q.empty()){
		int data = q.front().first;
		int depth = q.front().second;
		q.pop();
		
		if(data == k){
			result = depth;
			break;
		}
		if(data+1 <= MAX_1697 && data+1 >= 0 && !(visit[data+1])){
			q.push({data+1,depth+1});
			visit[data+1] = true;
		}
		if(2*data <= MAX_1697 && 2*data >= 0 && !(visit[2*data])){
			q.push({2*data,depth+1});
			visit[2*data] = true;
		}
		if(data-1 >= 0 && data-1 <= MAX_1697 && !(visit[data-1])){
			q.push({data-1,depth+1});
			visit[data-1] = true;
		}
	}
	cout<<result<<"\n";
	
	return 0;
}