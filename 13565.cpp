#include <iostream>
#include <queue>
#include <string>

using namespace std;

int m, n;
string str;
int insulator[1000][1000];
bool visited[1000][1000];
queue<pair<int,int>> q;
int dR[4] = {0,0,-1,1};
int dC[4] = {-1,1,0,0};
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>m>>n;
	
	for(int i = 0; i < m; i++){
		cin>>str;
		for(int j = 0; j < n; j++){
			insulator[i][j] = str[j] - 48;
		}
	}
	// for(int i = 0; i < m; i++){
	// 	for(int j = 0; j < n; j++){
	// 		cout<<insulator[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(int i = 0; i < n; i++){
		if(!insulator[0][i]){
			q.push({0,i});
			visited[0][i] = true;
		}
	}
	int r, c;
	int row, col;
	while(!q.empty()){
		r = q.front().first;
		c = q.front().second;
		q.pop();
		if(r == m-1){
			cout<<"YES";
			return 0;
		}
		
		for(int i = 0; i < 4; i++){
			row = r + dR[i];
			col = c + dC[i];
			if(row >= 0 && row < m && col >= 0 && col < n){
				if(!insulator[row][col] && !visited[row][col]){
					q.push({row,col});
					visited[row][col] = true;
				}
			}
		}
	}
	cout<<"NO";
	
	return 0;
}