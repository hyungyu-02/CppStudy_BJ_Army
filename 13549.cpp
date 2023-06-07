#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;
int weight[100001];

int findWeight(int s, int e){
	q.push(s);
	weight[s] = 0;
	
	int cur;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur == e){
			return weight[e];
		}
		
		if(cur < e){
			if(cur*2 >= 0 && cur*2 <= 100000 && weight[cur] < weight[cur*2]){
				q.push(cur*2);
				weight[cur*2] = weight[cur];
			}
			if(cur+1 >= 0 && cur+1 <= 100000 && weight[cur]+1 < weight[cur+1]){
				q.push(cur+1);
				weight[cur+1] = weight[cur]+1;
			}
			if(cur-1 >= 0 && cur-1 <= 100000 && weight[cur]+1 < weight[cur-1]){
				q.push(cur-1);
				weight[cur-1] = weight[cur]+1;
			}
		}else{
			if(cur-1 >= 0 && cur-1 <= 100000 && weight[cur]+1 < weight[cur-1]){
				q.push(cur-1);
				weight[cur-1] = weight[cur]+1;
			}
		}
		
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	
	fill_n(weight,100001,100001);
	
	cout<<findWeight(n, k);
	
	return 0;
}