#include <iostream>
#include <stack>
using namespace std;
int arr[1000000];
int nge[1000000];
int n;
stack<int> st;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	fill_n(nge,n,-1);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	
	st.push(0);
	int topVal;
	for(int i = 1; i < n; i++){
		while(!st.empty()){
			topVal = st.top();
			if(arr[topVal] < arr[i]){
				nge[topVal] = arr[i];
				st.pop();
			}else{
				break;
			}
		}
		st.push(i);
	}
	
	for(int i = 0; i < n; i++){
		cout<<nge[i]<<" ";
	}
	
	return 0;
}