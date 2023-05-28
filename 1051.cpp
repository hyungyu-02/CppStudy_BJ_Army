//#include "header.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int BJ_1051();

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); //cin과 cout의 속도를 높여줌
	
	return BJ_1051();
}


int BJ_1051(){
	int N, M;
	cin >> N >> M;
	
	int** arr = new int*[N];
	for(int i = 0; i < N; i++){
		arr[i] = new int[M];
	}
	// for(int i = 0; i < N; i++){
	// 	cin>>arr[i][0];
	// }
	// for(int i = 0; i < N; i++){
	// 	for(int k = M-1; k > 0; k--){
	// 		arr[i][k] = arr[i][0]%(10);
	// 		arr[i][0] /= 10;
	// 	}
	// }
	
	for(int i = 0; i < N; i++){
		string temp;
		cin>>temp;
		for(int j = 0; j < M; j++){
			arr[i][j] = temp[j] - '0';
		}
	}
	
	int result = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 1; k+j < M && k+i < N && k < min(N, M); k++){
				if(arr[i][j] == arr[i][j+k] && arr[i][j] == arr[i+k][j] && arr[i][j] == arr[i+k][j+k]){
					result = max(result,k+1);
				}
			}
		}
	}
	cout<<result*result<<endl;
	
	for(int i = 0; i < N; i++){
		delete[] arr[i];
	}
	delete[] arr;
	
	return 0;
}