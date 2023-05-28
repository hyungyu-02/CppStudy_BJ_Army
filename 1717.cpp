#include <iostream>
#include <vector>

using namespace std;

int parent[1000001];

int getTopParent(int a){
	if(parent[a] == a) return a;
	//return getTopParent(parent[a]);//?? return parent[a] = getTopParent(parent[a]);
	return parent[a] = getTopParent(parent[a]);
}
void unionParent(int a, int b){
	a = getTopParent(a);
	b = getTopParent(b);
	if(a > b) parent[a] = b;
	else parent[b] = a;
}
void sameGroup(int a, int b){
	a = getTopParent(a);
	b = getTopParent(b);
	if(a == b) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); //cin과 cout의 속도를 높여줌
	
	int n, m;
	cin>>n>>m;
	
	for(int i = 1; i < n+1; i++)
		parent[i] = i;
	
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin>>a>>b>>c;
		if(a == 0){
			unionParent(b, c);
		}else{
			sameGroup(b, c);
		}
	}
	
	return 0;
}