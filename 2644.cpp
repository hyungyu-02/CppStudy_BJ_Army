#include <iostream>
#include <queue>

using namespace std;

int n, A, B, m;
int x, y;
bool rel[101][101];
bool visited[101];
queue<pair<int,int>> q;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>A>>B>>m;
	
	for(int i = 0; i < m; i++){
		cin>>x>>y;
		rel[x][y] = true;
		rel[y][x] = true;
	}
	
	q.push({A,0});
	visited[A] = true;
	
	int pre, lev;
	while(!q.empty()){
		pre = q.front().first;
		lev = q.front().second;
		q.pop();
		if(pre == B){
			cout<<lev;
			return 0;
		}
		for(int i = 1; i <= n; i++){
			if(rel[pre][i] && !visited[i]){
				q.push({i,lev+1});
				visited[i] = true;
			}
		}
	}
	
	cout<<-1;
	
	return 0;
}