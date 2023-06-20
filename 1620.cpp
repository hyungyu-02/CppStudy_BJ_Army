#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n, m;
map<string, int> poke;
vector<string> v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	v.push_back("");
	string name;
	for(int i = 1; i <= n; i++){
		cin>>name;
		v.push_back(name);
		poke.insert({name, i});
	}
	
	string ques;
	for(int i = 0; i < m; i++){
		cin>>ques;
		if(ques[0] >= '0' && ques[0] <= '9'){
			cout<<v[stoi(ques)]<<"\n";
		}else{
			cout<<poke[ques]<<"\n";
		}
	}
	
	return 0;
}