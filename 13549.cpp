#include <iostream>
#include <set>

using namespace std;

int n, k;
set<pair<int,int>> s; //time, pos

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	
	s.insert({0,n});
	
	pair<int,int> p;
	int pos, time;
	while(!q.empty()){
		p = *(s.begin());
		time = p.first;
		pos = p.second;
		s.erase(s.begin());
		
		if(pos == k){
			cout<<time;
			return 0;
		}
		
		s.insert({time,pos*2})
	}
	
	
	
	return 0;
}