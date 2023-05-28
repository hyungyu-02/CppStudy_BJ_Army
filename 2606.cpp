#include <iostream>
#include <queue>

using namespace std;

int computer;
int pairs;
int rel[101][101];
int visited[101];
int cnt = 0;
queue<int> q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>computer;
	cin>>pairs;
	for(int i = 0; i < pairs; i++){
		int a, b;
		cin>>a>>b;
		rel[a][b] = 1;
		rel[b][a] = 1;
	}
	
	q.push(1);
	visited[1] = true;
	int pnt;
	
	while(!q.empty()){
		pnt = q.front();
		q.pop();
		for(int i = 1; i <= computer; i++){
			if(rel[pnt][i] && !visited[i]){
				q.push(i);
				cnt++;
				visited[i] = true;
			}
		}
	}
	cout<<cnt;
	return 0;
}