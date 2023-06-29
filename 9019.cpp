#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

int t;
int a, b;
queue<pair<int,string>> q;
bool visited[10000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t;
	
	while(t--){
		cin>>a>>b;
		
		while(!q.empty())
			q.pop();
		memset(visited, false, sizeof(visited));
		
		q.push({a,""});
		visited[a] = true;
		int cur;
		string proc;
		while(!q.empty()){
			cur = q.front().first;
			proc = q.front().second;
			q.pop();
			
			if(cur == b){
				cout<<proc<<"\n";
				break;
			}
			
			if(!visited[(cur*2)%10000]){
				q.push({(cur*2)%10000, proc+"D"});
				visited[(cur*2)%10000] = true;
			}
			if(!cur){
				if(!visited[9999]){
					q.push({9999, proc+"S"});
					visited[9999] = true;
				}
			}else{
				if(!visited[cur-1]){
					q.push({cur-1, proc+"S"});
					visited[cur-1] = true;
				}
			}
			
			int L = cur/1000 + (cur%1000)*10;
			if(!visited[L]){
				q.push({L, proc+"L"});
			}
			
			int R = (cur%10)*1000 + cur/10;
			if(!visited[R]){
				q.push({R, proc+"R"});
			}
		}
	}
	
	return 0;
}