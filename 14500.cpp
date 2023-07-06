#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int board[500][500];
bool visited[500][500];
int maxRet = 0;
int dR[4] = {0,0,-1,1};
int dC[4] = {-1,1,0,0};

void dfs(int r, int c, int score, int lev){
    visited[r][c] = true;
    if(lev >= 4){
        score += board[r][c];
        maxRet = max(maxRet, score);
        visited[r][c] = false;
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int nR = r + dR[i];
        int nC = c + dC[i];
        if(nR >= 0 && nR < n && nC >= 0 && nC < m && !visited[nR][nC]){
            dfs(nR, nC, score+board[nR][nC], lev+1);
        }
    }
    visited[r][c] = false;
    return;
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dfs(i, j, board[i][j], 1);
        }
    }

    cout<<maxRet;



    return 0;
}
