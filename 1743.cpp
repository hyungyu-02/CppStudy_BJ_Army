#include <iostream>
#include <queue>

using namespace std;

int merge(int r, int c);

int n, m, k;
int point[101][101] = {{0, }, };
bool visited[101][101];
queue<pair<int,int>> q;

int dR[] = {0,0,-1,1};
int dC[] = {1,-1,0,0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	// for(int i = 0; i < 10; i++){
	// 	for(int j = 0; j < 10; j++){
	// 		cout<<point[i][j]<<" ";
	// 	}
	// 	cout<<endl;	
	// }
	
	cin>>n>>m>>k;
	while(k--){
		int r, c;
		cin>>r>>c;
		point[r][c] = 1;
	}
	
	int max = 0;
	int size;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(point[i][j] && !(visited[i][j])){
				size = merge(i,j);
				if(max < size){
					max = size;
				}
			}
		}
	}
	
	cout<<max;
	
	return 0;
}

int merge(int r, int c){
	int s = 0;
	while(!q.empty())
		q.pop();
	q.push({r,c});
	visited[r][c] = true;
	
	while(!q.empty()){
		r = q.front().first;
		c = q.front().second;
		q.pop();
		s++;
		//visited[r][c] = true;
		
		for(int i = 0; i < 4; i++){
			int row = r+dR[i];
			int col = c+dC[i];
			
			if(row < 1 || row > n || col < 1 || col > m)
				continue;
			if(point[row][col] && !(visited[row][col])){
				q.push({row,col});
				visited[row][col] = true;
			}
		}
	}
	return s;
}