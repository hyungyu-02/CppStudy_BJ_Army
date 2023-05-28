#include <iostream>
#include <queue>

using namespace std;

int m, n;
int box[1000][1000];
queue<pair<pair<int,int>,int>> q;// {{r, c}, day}
int dR[] = {0, 0, -1, 1};
int dC[] = {-1, 1, 0, 0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>m>>n;
	bool already = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>box[i][j];
			if(!box[i][j]) already = false;
		}
	}
	if(already){
		cout<<0;
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(box[i][j] == 1){
				q.push({{i,j},0});
			}
		}
	}
	if(q.empty()){
		cout<<-1;
		return 0;
	}
	
	int r, c, day;
	int row, col;
	while(!q.empty()){
		r = q.front().first.first;
		c = q.front().first.second;
		day = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			row = r + dR[i];
			col = c + dC[i];
			if(row >= 0 && row < n && col >= 0 && col < m){
				if(box[row][col] == 0){
					q.push({{row,col},day+1});
					box[row][col] = day+1;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(box[i][j] == 0){
				cout<<-1;
				return 0;
			}
		}
	}
	
	cout<<day;
	return 0;
}