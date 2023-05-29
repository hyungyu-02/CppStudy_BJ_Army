#include <iostream>
#include <queue>

using namespace std;

int n, m, component = 0;
int rel[1001][1001];
bool visited[1001];
queue<int> q;

void BFS(int root){
	q.push(root);
	visited[root] = true;
	int now;
	while(!q.empty()){
		now = q.front();
		q.pop();
		
		for(int i = 1; i <= n; i++){
			if(rel[now][i] && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin>>a>>b;
		rel[a][b] = 1;
		rel[b][a] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			BFS(i);
			component++;
		}
	}
	
	cout<<component<<endl;
	
	return 0;
}