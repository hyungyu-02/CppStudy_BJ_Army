#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int board[500][500];
bool visited[500][500];
int maxRet = 0;
int dR[4] = {0,0,-1,1};
int dC[4] = {-1,1,0,0};

void dfs(int r, int c, int score, int lev){
    if(lev >= 4){
        maxRet = max(maxRet, score);
		if(score == 20){
			cout<<"\n ** find 20!! ** "<<endl;
		}
        return;
    }
    
    for(int i = 0; i < 4; i++){
		int nR = r + dR[i];
		int nC = c + dC[i];
		if(nR >= 0 && nR < n && nC >= 0 && nC < m && !visited[nR][nC]){
			visited[nR][nC] = true;
			dfs(nR, nC, score+board[nR][nC], lev+1);
			visited[nR][nC] = false;
		}
    }
    return;
}

void Tshape(){
	// ㅏ
	for(int i = 0; i < n-2; i++){
		for(int j = 0; j < m-1; j++){
			if((board[i][j] + board[i+1][j] + board[i+2][j] + board[i+1][j+1]) > maxRet){
				//maxRet = score;
				cout<<"ㅏ changed : "<<i<<" "<<j<<endl;
			}
			maxRet = max(maxRet, (board[i][j] + board[i+1][j] + board[i+2][j] + board[i+1][j+1]));
		}
	}
	// ㅜ
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < m-2; j++){
			if((board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1]) > maxRet){
				//maxRet = score;
				cout<<"ㅜ changed : "<<i<<" "<<j<<endl;
			}
			maxRet = max(maxRet, (board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1]));
		}
	}
	// ㅓ
	for(int i = 0; i < n-2; i++){
		for(int j = 0; j < m-1; j++){
			if((board[i][j+1] + board[i+1][j+1] + board[i+2][j+1] + board[i][j+1]) > maxRet){
				//maxRet = score;
				cout<<"ㅓ changed : "<<i<<" "<<j<<endl;
			}
			maxRet = max(maxRet, (board[i][j+1] + board[i+1][j+1] + board[i+2][j+1] + board[i+1][j]));
		}
	}
	// ㅗ
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < m-2; j++){
			if((board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+1]) > maxRet){
				//maxRet = score;
				cout<<"ㅗ changed : "<<i<<" "<<j<<endl;
			}
			maxRet = max(maxRet, (board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+1]));
		}
	}
	
	return;
}

int main(){
	memset(visited, false, sizeof(visited));
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>board[i][j];
        }
    }
	// for(int i = 0; i < n; i++){
	// for(int j = 0; j < m; j++){
	// cout<<board[i][j]<<" ";
	// }
	// 	cout<<endl;
	// }

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			visited[i][j] = true;
			dfs(i, j, board[i][j], 1);
			visited[i][j] = false;
		}
	}
	
	Tshape();

	cout<<maxRet;
	
    return 0;
}
