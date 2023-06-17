#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, m;
map<string,string> LandP;
vector<string> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	string link, pwd;
	for(int i = 0; i < n; i++){
		cin>>link>>pwd;
		LandP.insert({link,pwd});
	}
	// for(auto it = LandP.begin(); it != LandP.end(); it++){
	// 	cout<<it->first<<" "<<it->second<<endl;
	// }
	for(int i = 0; i < m; i++){
		cin>>link;
		v.push_back(link);
	}
	for(int i = 0; i < m; i++){
		auto it = LandP.find(v[i]);
		cout<<it->second<<"\n";
	}
	
	return 0;
}