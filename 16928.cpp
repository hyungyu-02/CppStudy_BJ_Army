#include <iostream>
#include <queue>

using namespace std;

int n, m;
int board[101];
queue<pair<int,int>> q; //현재위치, 주사위 굴린 횟수

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i = 0; i < n+m; i++){
		int a, b;
		cin>>a>>b;
		board[a] = b;
	}
	q.push({1,0});
	
	int pos, cnt;
	while(!q.empty()){
		pos = q.front().first;
		cnt = q.front().second;
		q.pop();
		if(pos >= 94){
			cout<<cnt+1;
			break;
		}
		
		for(int i = 1; i <= 6; i++){
			if(board[pos+i]){
				q.push({board[pos+i],cnt+1});
			}
		}
		for(int i = 6; i > 0; i--){
			if(!board[pos+i]){
				q.push({pos+i,cnt+1});
				break;
			}
		}
		
	}
	return 0;
}