#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
int mat[101][101];
int ans[101][101];
bool visited[101];
queue<int> q;

bool able(int start, int destin){
	while(!q.empty())
		q.pop();
	
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++){
		if(mat[start][i]){
			q.push(i);
			visited[i] = true;
		}
	}
	int cur;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur == destin){
			return true;
		}
		for(int i = 1; i <= n; i++){
			if(mat[cur][i] && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return false;
}

int main(){
	cin>>n;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>mat[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(able(i,j))
				ans[i][j] = 1;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}