#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l, c;
vector<char> candid;
vector<char> comb;

bool check(){
	int cnt = 0;
	for(auto c : comb){
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
			cnt++;
		}
	}
	if(cnt > 0 && l - cnt > 1)
		return true;
	return false;
}

void dfs(int lev){
	if(comb.size() == l){
		if(check()){
			for(int i = 0; i < l; i++){
				cout<<comb[i];
			}
			cout<<"\n";
		}
		return;
	}
	for(int i = lev; i < c; i++){
		comb.push_back(candid[i]);
		dfs(i+1);
		comb.pop_back();
	}
	return;
}

int main(){
	cin>>l>>c;
	char temp;
	for(int i = 0; i < c; i++){
		cin>>temp;
		candid.push_back(temp);
	}
	sort(candid.begin(), candid.end());
	
	dfs(0);
	
	return 0;
}