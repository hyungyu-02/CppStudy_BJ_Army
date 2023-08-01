#include <iostream>
#include <queue>
using namespace std;

int t, k;
priority_queue<long long, vector<long long>, greater<long long>> q;
long long cnt;

int main(){
	cin>>t;
	while(t--){
		cnt = 0;
		while(!q.empty()){
			q.pop();
		}
		cin>>k;
		int temp;
		for(int i = 0; i < k; i++){
			cin>>temp;
			q.push(temp);
		}
		long long a, b;
		while(q.size() > 1){
			a = q.top(); q.pop();
			b = q.top(); q.pop();
			cnt += a + b;
			q.push(a+b);
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}