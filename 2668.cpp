#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int n;
int arr[101];
list<int> ban;
int bannedNum = 0;

void cycle(int idx){
	if(arr[idx] < 0){
		return;
	}
	int next = arr[idx];
	arr[idx] = 0 - arr[idx];
	bannedNum++;
	
	for(int i = 1; i <= n; i++){
		if(i != idx){
			if(arr[i] == next){
				return;
			}
		}
	}
	
	cycle(next);
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
		ban.push_back(i);
	}
	for(int i = 1; i <= n; i++){
		ban.remove(arr[i]);
	}
	
	for(auto it = ban.begin(); it != ban.end(); it++){
		cycle(*(it));
	}
	
	cout<<n-bannedNum<<endl;
	
	sort(arr,arr+n+1);
	
	for(int i = bannedNum+1; i <= n; i++){
		cout<<arr[i]<<endl;
	}
	
	return 0;
}