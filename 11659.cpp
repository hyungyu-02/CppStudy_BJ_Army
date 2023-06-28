#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	
	v.push_back(0);
	int temp;
	for(int i = 0; i < n; i++){
		cin>>temp;
		v.push_back(temp+v[i]);
	}
	
	int start, end;
	for(int i = 0; i < m; i++){
		cin>>start>>end;
		
		cout<<v[end] - v[start-1]<<"\n";
	}
	
	return 0;
}