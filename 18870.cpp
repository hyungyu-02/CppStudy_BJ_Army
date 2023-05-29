#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> origin;

int main(){//vector, lower_bound, unique, erase
	cin>>n;
	int a;
	for(int i = 0; i < n; i++){
		cin>>a;
		origin.push_back(a);
	}
	vector<int> copy(origin);
	sort(copy.begin(), copy.end());
	copy.erase(unique(copy.begin(), copy.end()), copy.end());
	
	for(int i = 0; i < n; i++){
		cout<<lower_bound(copy.begin(), copy.end(), origin[i]) - copy.begin()<<" ";
	}
	
	return 0;
}