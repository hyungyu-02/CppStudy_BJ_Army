#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
int arr[100][100];
queue<pair<pair<int,int>,int>> q;
bool visited[100][100];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); //cin과 cout의 속도를 높여줌
	
	cin>>n>>m;
	
	for(int i = 0; i < n; i++){
		string temp;
		cin>>temp;
		for(int j = 0; j < m; j++){
			arr[i][j] = temp[j] - '0';
		}
	}
	
	q.push({{0,0},1});
	
	while(!q.empty()){
		pair<int,int> pos = q.front().first;
		int x = pos.first;
		int y = pos.second;
		int depth = q.front().second;
		q.pop();
		if(visited[x][y]) continue;
		visited[x][y] = true;
		
		if(x == n-1 && y == m-1){
			cout<<depth<<endl;
			break;
		}
		
		if(x+1 >= 0 && x+1 < n && arr[x+1][y] && !visited[x+1][y]){
			q.push({{x+1,y}, depth+1});
		}
		if(y+1 >= 0 && y+1 < m && arr[x][y+1] && !visited[x][y+1]){
			q.push({{x,y+1}, depth+1});
		}
		if(x-1 >= 0 && x-1 < n && arr[x-1][y] && !visited[x-1][y]){
			q.push({{x-1,y}, depth+1});
		}
		if(y-1 >= 0 && y-1 < n && arr[x][y-1] && !visited[x][y-1]){
			q.push({{x,y-1}, depth+1});
		}
		
	}
	
	return 0;
}