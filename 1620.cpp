#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, m;
map<string, int> poke;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	string name;
	for(int i = 1; i <= n; i++){
		cin>>name;
		poke.insert({name, i});
	}
	
	string ques;
	for(int i = 0; i < m; i++){
		cin>>ques;
		if(ques[0] >= '0' && ques[0] <= '9'){
			
		}else{
			
		}
	}
	
	return 0;
}