#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

int n;
int ground[25][25];
bool visited[25][25];
string str;
queue<pair<int,int>> q;
int dR[4] = {0,0,-1,1};
int dC[4] = {-1,1,0,0};
multiset<int> se;

int findGroupSize(int r, int c){
	int size = 1;
	q.push({r,c});
	visited[r][c] = true;
	
	int row,col;
	while(!q.empty()){
		row = q.front().first;
		col = q.front().second;
		q.pop();
		
		int R, C;
		for(int i = 0; i < 4; i++){
			R = row+dR[i];
			C = col+dC[i];
			if(R >= 0 && R < n && C >= 0 && C < n){
				if(ground[R][C] && !visited[R][C]){
					q.push({R,C});
					visited[R][C] = true;
					size++;
				}
			}
		}
	}
	return size;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>str;
		for(int j = 0; j < n; j++){
			ground[i][j] = str[j]-48;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(ground[i][j] && !visited[i][j]){
				se.insert(findGroupSize(i,j));
			}
		}
	}
	cout<<se.size()<<"\n";
	for(auto it = se.begin(); it != se.end(); it++){
		cout<<*(it)<<"\n";
	}
	
	return 0;
}