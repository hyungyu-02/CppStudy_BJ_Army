#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct info{
	int R; int C; int D;
};

int n, m;
int map[1002][1002];
int dist[1002][1002];
bool visited[1002][1002];
// queue<pair<pair<int,int>,int>> q; // 좌표값, 거리
queue<info> q; // 좌표값, 거리
int dR[4] = {0,0,-1,1};
int dC[4] = {-1,1,0,0};


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dist, 0, sizeof(dist));
	memset(visited, false, sizeof(visited));
	cin>>n>>m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>map[i][j];
		}
	}
	
	bool findDestin = false;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == 2){
				q.push({i, j, 0});
				dist[i][j] = 0;
				visited[i][j] = true;
				findDestin = true;
				break;
			}
		}
		if(findDestin)
			break;
	}
	
	info IN;
	int r, c, nR, nC;
	int d;
	while(!q.empty()){
		IN = q.front();
		// r = q.front().first.first;
		// c = q.front().first.second;
		// d = q.front().second;
		r = IN.R;
		c = IN.C;
		d = IN.D;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			nR = r + dR[i];
			nC = c + dC[i];
			if(nR >= 0 && nR < n && nC >= 0 && nC < m){
				if(!visited[nR][nC] && map[nR][nC]){
					q.push({nR, nC, d+1});
					visited[nR][nC] = true;
					dist[nR][nC] = d+1;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j]){
				if(map[i][j]){
					dist[i][j] = -1;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}