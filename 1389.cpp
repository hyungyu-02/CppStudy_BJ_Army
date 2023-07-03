#include <iostream>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

int n, m;

int rel[101][101];
int farLev[101][101];
queue<pair<int,int>> q;//사람, 베이컨 레벨
bool visited[101];

int findDist(int a, int b){
	int cnt = 1;
	memset(visited, false, sizeof(visited));
	while(!q.empty()) q.pop();
	
	q.push({a, 0}); visited[a] = true;
	int cur, lev;
	while(!q.empty()){
		cur = q.front().first;
		lev = q.front().second;
		q.pop();
		if(cur == b){
			return lev;
		}
		for(int i = 1; i <= n; i++){
			if(rel[cur][i] && !visited[i]){
				q.push({i,lev+1});
				visited[i] = true;
			}
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	int a, b;
	for(int i = 0; i < m; i++){
		cin>>a>>b;
		rel[a][b] = 1;
		rel[b][a] = 1;
	}
	
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
			farLev[i][j] = findDist(i,j);
			farLev[j][i] = farLev[i][j];
		}
	}
	
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++){
	// 		cout<<farLev[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	int kb[101];
	set<pair<int,int>> s;
	for(int i = 1; i <= n; i++){
		int k = 0;
		for(int j = 1; j <= n; j++){
			k += farLev[i][j];
		}
		s.insert({k,i});
	}
	auto it = s.begin();
	cout<<(*it).second;
	
	return 0;
}