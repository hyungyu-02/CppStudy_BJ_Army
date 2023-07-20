#include <iostream>
#include <queue>
using namespace std;

long long a, b;
queue<pair<long long,long long>> q;

int main(){
	cin>>a>>b;
	q.push({a,1});
	long long cur, lev;
	while(!q.empty()){
		cur = q.front().first;
		lev = q.front().second;
		q.pop();
		if(cur == b){
			cout<<lev;
			return 0;
		}
		if(cur <= b){
			q.push({cur*2, lev+1});
			q.push({cur*10 + 1, lev+1});
		}
	}
	cout<<-1;
	return 0;
}