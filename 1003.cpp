#include <iostream>
#include <vector>

using namespace std;

int t, n;

vector<pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t;
	
	v.push_back({1,0});
	v.push_back({0,1});
	
	while(t--){
		cin>>n;
		if(n <= v.size()-1){
			cout<<v[n].first<<" "<<v[n].second<<"\n";
		}
		else{
			for(int i = v.size(); i <= n; i++){
				v.push_back({v[i-1].first+v[i-2].first, v[i-1].second+v[i-2].second});
				
			}
			cout<<v[n].first<<" "<<v[n].second<<"\n";
		}
	}
	
	return 0;
}