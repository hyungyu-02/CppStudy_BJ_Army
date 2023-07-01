#include <iostream>
#include <queue>

using namespace std;

int n, info;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
//second : -1 : 음수 , 1 : 양수

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	while(n--){
		cin>>info;
		if(!info){
			if(q.empty()){
				cout<<0<<"\n";
			}else{
				cout<<q.top().first*q.top().second<<"\n";
				q.pop();
			}
		}else if(info < 0){
			info = -info;
			q.push({info,-1});
		}else{
			q.push({info,1});
		}
	}
	
	return 0;
}