#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> q;
int cnt = 0;

int main(){
	cin>>n;
	int temp;
	for(int i = 0; i < n; i++){
		cin>>temp;
		q.push(temp);
	}
	int a, b;
	while(q.size() > 1){
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		cnt += a + b;
		q.push(a+b);
	}
	cout<<cnt;
	
	return 0;
}