#include <iostream>
#include <queue>

using namespace std;

int m, n;
int banner[250][250];
bool visited[250][250];
queue<pair<int,int>> q;
int dR[8] = {-1,-1,-1,0,1,1,1,0};
int dC[8] = {-1,0,1,1,1,0,-1,-1};
int num = 0;

void scaning(int r, int c){
	q.push({r,c});
	visited[r][c] = true;
	
	int row, col, nrow, ncol;
	while(!q.empty()){
		row = q.front().first;
		col = q.front().second;
		q.pop();
		
		for(int i = 0; i < 8; i++){
			nrow = row + dR[i];
			ncol = col + dC[i];
			if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
				if(banner[nrow][ncol] && !visited[nrow][ncol]){
					q.push({nrow,ncol});
					visited[nrow][ncol] = true;
				}
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>m>>n;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin>>banner[i][j];
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(banner[i][j] && !visited[i][j]){
				scaning(i,j);
				num++;
			}
		}
	}
	
	cout<<num;
	
	return 0;
}