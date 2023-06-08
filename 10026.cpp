#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;
string str;
int grid[100][100];//1 : R , 2 : G , 0 : B
bool visited[100][100];
queue<pair<int,int>> q;
int dR[4] = {0,0,-1,1};
int dC[4] = {-1,1,0,0};

void BFS_weak(int r, int c){
	int color = grid[r][c];
	
	q.push({r,c});
	visited[r][c] = true;
	
	int row, col, nrow, ncol;
	while(!q.empty()){
		row = q.front().first;
		col = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			nrow = row + dR[i];
			ncol = col + dC[i];
			if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
				if((color == grid[nrow][ncol] || (color*grid[nrow][ncol])) && !visited[nrow][ncol]){
					q.push({nrow,ncol});
					visited[nrow][ncol] = true;
				}
			}
		}
	}
	return;
}
void BFS_norm(int r, int c){
	int color = grid[r][c];
	
	q.push({r,c});
	visited[r][c] = true;
	
	int row, col, nrow, ncol;
	while(!q.empty()){
		row = q.front().first;
		col = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			nrow = row + dR[i];
			ncol = col + dC[i];
			if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
				if(color == grid[nrow][ncol] && !visited[nrow][ncol]){
					q.push({nrow,ncol});
					visited[nrow][ncol] = true;
				}
			}
		}
	}
	return;
}

pair<int,int> findArea(){
	int area_norm = 0;
	int area_weak = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]){
				BFS_norm(i,j);
				area_norm++;
			}
		}
	}
	
	fill_n(visited[0], 10000, false);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]){
				BFS_weak(i,j);
				area_weak++;
			}
		}
	}
	
	return {area_norm, area_weak};
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>str;
		for(int j = 0; j < n; j++){
			if(str[j] == 'R'){
				grid[i][j] = 1;
			}else if(str[j] == 'G'){
				grid[i][j] = 2;
			}
		}
	}
	
	auto p = findArea();
	cout<<p.first<<" "<<p.second;
	
	return 0;
}