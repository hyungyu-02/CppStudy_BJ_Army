#include <iostream>
#include <set>
#include <queue>

using namespace std;

struct LandR{
	set<int> left; set<int> right;
};

int n, m;
//int LandR[100][2];
LandR marble[100];
bool visited[100];
int impossible = 0;

void BFS(int idx){
	queue<int> q;
	fill_n(visited, n+1, false);
	
	for(auto it = marble[idx].left.begin(); it != marble[idx].left.end(); it++){
		q.push(*(it));
		visited[*(it)] = true;
	}
	
	int cur;
	while(!q.empty()){
		cur = q.front(); q.pop();
		
		for(auto it = marble[cur].left.begin(); it != marble[cur].left.end(); it++){
			if(!visited[*(it)]){
				q.push(*(it));
				visited[*(it)] = true;
				marble[idx].left.insert(*(it));
			}
		}
	}
	
	fill_n(visited, n+1, false);
	
	for(auto it = marble[idx].right.begin(); it != marble[idx].right.end(); it++){
		q.push(*(it));
		visited[*(it)] = true;
	}
	
	while(!q.empty()){
		cur = q.front(); q.pop();
		
		for(auto it = marble[cur].right.begin(); it != marble[cur].right.end(); it++){
			if(!visited[*(it)]){
				q.push(*(it));
				visited[*(it)] = true;
				marble[idx].right.insert(*(it));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	int a, b;
	for(int i = 0; i < m; i++){
		cin>>a>>b;
		marble[a].left.insert(b);
		marble[b].right.insert(a);
	}
	
	for(int i = 1; i <= n; i++){
		BFS(i);
	}
	
	for(int i = 1; i <= n; i++){
		if(marble[i].left.size() > (n-1)/2){
			impossible++;
		}else if(marble[i].right.size() > (n-1)/2){
			impossible++;
		}
	}
	
	cout<<impossible;
	
	return 0;
}