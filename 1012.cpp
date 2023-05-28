#include <iostream>
#include <queue>

using namespace std;

int t, m, n, k;
queue<pair<int,int>> q;
int field[50][50];
bool visited[50][50];
int dR[] = {0, 0, -1, 1};
int dC[] = {-1, 1, 0, 0};

int earthworm();

int main(){
	cin>>t;
	
	while(t--){
		cout<<earthworm()<<"\n";
	}
	
	return 0;
}

int earthworm(){
	for(int i = 0; i < 50; i++){
		for(int j = 0; j < 50; j++){
			field[i][j] = 0;
			visited[i][j] = false;
		}
	}
	while(!q.empty())
		q.pop();
	
	int ret = 0;
	
	cin>>m>>n>>k;
	
	for(int i = 0; i < k; i++){
		int c, r;
		cin>>c>>r;
		field[r][c] = 1;
	}
	for(int y = 0; y < n; y++){
		for(int x = 0; x < m; x++){
			if(field[y][x] && !visited[y][x]){
				q.push({y,x});
				visited[y][x] = true;
				ret++;
				
				while(!q.empty()){
					int r = q.front().first;
					int c = q.front().second;
					q.pop();
					for(int i = 0; i < 4; i++){
						int row = r + dR[i];
						int col = c + dC[i];
						if(row >= 0 && row < n && col >= 0 && col < m){
							if(field[row][col] && !visited[row][col]){
								q.push({row,col});
								visited[row][col] = true;
							}
						}
					}
				}
			}
		}
	}
	
	return ret;
}