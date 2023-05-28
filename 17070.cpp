#include <iostream>
#include <queue>

using namespace std;

struct pipe{
	int r; int c; int stat;
};//파이프의 남동쪽 끝 좌표와 상태정보(1 : 가로, 2 ; 세로, 3 : 대각선)

int n;
int house[17][17];
int ways = 0;
queue<pipe> q;

void checkAndPush(pipe p){
	if(p.stat == 1 && p.c < n){
		if(house[p.r][p.c + 1] == 0){
			q.push({p.r, p.c + 1, 1});
			if(house[p.r + 1][p.c + 1] == 0 && house[p.r + 1][p.c] == 0 && p.r < n){
				q.push({p.r + 1, p.c + 1, 3});
			}
		}
	}else if(p.stat == 2 && p.r < n){
		if(house[p.r + 1][p.c] == 0){
			q.push({p.r + 1, p.c, 2});
			if(house[p.r + 1][p.c + 1] == 0 && house[p.r][p.c + 1] == 0 && p.c < n){
				q.push({p.r + 1, p.c + 1, 3});
			}
		}
	}else if(p.stat == 3){
		if(house[p.r][p.c + 1] == 0 && p.c < n){
			q.push({p.r, p.c + 1, 1});
		}
		if(house[p.r + 1][p.c] == 0 && p.r < n){
			q.push({p.r + 1, p.c, 2});
		}
		if(house[p.r][p.c + 1] == 0 && house[p.r + 1][p.c] == 0 && house[p.r + 1][p.c + 1] == 0 && p.c < n && p.r < n){
			q.push({p.r + 1, p.c + 1, 3});
		}
	}
	return;
}

int main(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>house[i][j];
		}
	}
	q.push({1,2,1});
	
	pipe p;
	while(!q.empty()){
		p = q.front();
		q.pop();
		if(p.r == n && p.c == n){
			ways++;
		}else{
			checkAndPush(p);
		}
	}
	cout<<ways;
	
	return 0;
}