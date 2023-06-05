//multiset 으로 풂
#include <iostream>
#include <set> //자동 오름차순 정렬, 중복 값 허용, 중위 순회 사용

using namespace std;

int t, k;
char order;
int info;
multiset<int> ms;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>k;
		ms.clear();
		while(k--){
			cin>>order;
			cin>>info;
			if(order == 'I'){
				ms.insert(info);
			}else{
				if(ms.size() > 0){
					if(info == -1){
						auto it = ms.begin();
						ms.erase(it);
					}else{
						auto it = ms.end();
						it--;
						ms.erase(it);
					}
				}
			}
		}
		if(ms.size() > 0){
			auto start = ms.begin();
			auto end = ms.end();
			end--;
			cout<<*end<<" "<<*start<<endl;
		}else{
			cout<<"EMPTY"<<endl;
		}
	}
	
	return 0;
}