#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int t, n;
string str[100000];

int findDistance(string str1, string str2){
	int d = 0;
	for(int i = 0; i < 4; i++){
		if(str1[i] != str2[i])
			d++;
	}
	return d;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>t;
	
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>str[i];
		}
		if(n > 32){
			cout<<0<<"\n";
			continue;
		}
		int mini = 12;
		int cur;
		for(int i = 0; i < n-2; i++){
			for(int j = i+1; j < n-1; j++){
				cur = findDistance(str[i], str[j]);
				for(int x = j+1; x < n; x++){
					mini = min(mini, cur+findDistance(str[i], str[x])+findDistance(str[j], str[x]));
				}
			}
		}
		
		cout<<mini<<"\n";
	}
	
	return 0;
}