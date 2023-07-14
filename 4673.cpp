#include <iostream>
using namespace std;
int main(){
	bool selfNum[10001];
	fill_n(selfNum, 10001, false);
	int cnt = 1;
	while(true){
		if(cnt > 10000){
			break;
		}
		int idx = cnt;
		int cur = cnt;
		while(cur >= 1){
			idx += cur % 10;
			cur = cur/10;
		}
		if(idx <= 10000)
			selfNum[idx] = true;
		cnt++;
	}
	for(int i = 1; i < 10000; i++){
		if(!selfNum[i]){
			cout<<i<<"\n";
		}
	}
	return 0;
}