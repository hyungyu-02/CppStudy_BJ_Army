#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int t, n;
map<string, int> m;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t;
	
	while(t--){
		cin>>n;
		m.clear();
		string name, sort;
		for(int i = 0; i < n; i++){
			cin>>name>>sort;
			auto it = m.find(sort);
			if(it != m.end()){
				it->second++;
			}else{
				m.insert({sort,1});
			}
		}
		
		int num = 1;
		for(auto it = m.begin(); it != m.end(); it++){
			num *= (it->second + 1);
		}
		cout<<num-1<<"\n";
	}
	
	return 0;
}