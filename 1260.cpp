#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
int rel[1001][1001];
bool visited[1001];
queue<int> q;

void DFS(int v);
void BFS(int v);

int main(){
	cin>>n>>m>>v;
	
	for(int i = 1; i <= m; i++){
		int a, b;
		cin>>a>>b;
		rel[a][b] = 1;
		rel[b][a] = 1;
	}
	DFS(v);
	cout<<endl;
	for(int i = 0; i < 1001; i++){
		visited[i] = false;
	}
	BFS(v);
	
	return 0;
}

void DFS(int v){
	cout<<v<<" ";
	visited[v] = true;
	for(int i = 1; i <= n; i++){
		if(rel[v][i] && !visited[i]){
			DFS(i);
		}
	}
	return;
}
void BFS(int v){
	q.push(v);
	visited[v] = true;
	while(!q.empty()){
		int pos = q.front();
		q.pop();
		cout<<pos<<" ";
		for(int i = 1; i <= n; i++){
			if(rel[pos][i] && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return;
}