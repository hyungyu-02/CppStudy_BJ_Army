#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n, info;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	while(n--){
		cin>>info;
		if(info){
			pq.push(info);
		}else{
			if(pq.empty()){
				cout<<0<<"\n";
			}else{
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}
	}
	
	return 0;
}