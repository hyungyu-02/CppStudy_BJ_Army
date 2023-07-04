#include <iostream>

using namespace std;

int t;
int m, n, x, y;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>m>>n>>x>>y;
		if(x == y){
			cout<<x<<"\n";
		}else if(x > y){
			int a = y; int b = y;
			int count = y;
			
			while(true){
				a += n;
				a = a % m;
			}
		}
		
		
		
		
	}
	
	return 0;
}