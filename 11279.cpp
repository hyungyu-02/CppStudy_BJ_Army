#include <iostream>
#include <queue>

using namespace std;

int n, info;
priority_queue<int, vector<int>> q;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	while(n--){
		cin>>info;
		if(info>0){
			q.push(info);
		}else{
			if(q.empty()){
				cout<<0<<"\n";
			}else{
				cout<<q.top()<<"\n";
				q.pop();
			}
		}
	}
	
	return 0;
}