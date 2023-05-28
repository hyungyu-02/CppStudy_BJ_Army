#include <iostream>
#include <queue>

using namespace std;

struct tomato{
	int R, C, H, D;
};

int m, n, h;
int box[100][100][100];
queue<tomato> q;
int dR[] = {0, 0, 0, 0, -1, 1};
int dC[] = {0, 0, -1, 1, 0, 0};
int dH[] = {-1, 1, 0, 0, 0, 0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>m>>n>>h;
	
	bool already = true;
	
	for(int k = 0; k < h; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>box[k][i][j];
				if(!box[k][i][j]) already = false;
			}
		}
	}
	
	if(already){
		cout<<0;
		return 0;
	}
	
	for(int k = 0; k < h; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(box[k][i][j] == 1){
					q.push({i, j, k, 0});
				}
			}
		}
	}
	
	if(q.empty()){
		cout<<-1;
		return 0;
	}
	
	int r, c, he, day;
	int row, col, hei;
	while(!q.empty()){
		r = q.front().R;
		c = q.front().C;
		he = q.front().H;
		day = q.front().D;
		q.pop();
		
		for(int i = 0; i < 6; i++){
			row = r + dR[i];
			col = c + dC[i];
			hei = he + dH[i];
			if(row >= 0 && row < n && col >= 0 && col < m && hei >= 0 && hei < h){
				if(box[hei][row][col] == 0){
					q.push({row,col,hei,day+1});
					box[hei][row][col] = day+1;
				}
			}
		}
	}
	
	for(int k = 0; k < h; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(box[k][i][j] == 0){
					cout<<-1;
					return 0;
				}
			}
		}
	}
	
	cout<<day;
	return 0;
}