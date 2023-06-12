#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
int campus[600][600];// 0 : 벽 , 1 : 빈공간 , 2 : 사람 , 3 : 도연이
bool visited[600][600];
int dR[4] = {0,0,-1,1};
int dC[4] = {-1,1,0,0};
string str;
queue<pair<int,int>> q;
int friendNum;

int findFriend(int x, int y){
	int frNum = 0;
	q.push({x,y});
	visited[x][y] = true;
	
	int r, c, row, col;
	while(!q.empty()){
		r = q.front().first;
		c = q.front().second;
		q.pop();
		
		if(campus[r][c] == 2){
			frNum++;
		}
		
		for(int i = 0; i < 4; i++){
			row = r + dR[i];
			col = c + dC[i];
			
			if(row >= 0 && row < n && col >= 0 && col < m){
				if(!visited[row][col] && campus[row][col]){
					q.push({row,col});
					visited[row][col] = true;
				}
			}
		}
	}
	
	return frNum;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x, y;
	
	cin>>n>>m;
	
	for(int i = 0; i < n; i++){
		cin>>str;
		for(int j = 0; j < m; j++){
			if(str[j] == 'O'){
				campus[i][j] = 1;
			}else if(str[j] == 'P'){
				campus[i][j] = 2;
			}else if(str[j] == 'X'){
				campus[i][j] = 0;
			}else{
				campus[i][j] = 3;
				x = i;
				y = j;
			}
		}
	}
	
	friendNum = findFriend(x, y);
	
	if(friendNum){
		cout<<friendNum;
	}else{
		cout<<"TT";
	}
	
	return 0;
}