#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int total = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	int a;
	for(int i = 0; i < n; i++){
		cin>>a;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			total += v[j];
		}
	}
	
	cout<<total;
	
	return 0;
}