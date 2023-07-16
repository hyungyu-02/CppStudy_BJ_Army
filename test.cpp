#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

void testFunc(int arr[][10]){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int arr[10][10];
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			arr[i][j] = i+j;
		}
	}
	testFunc(arr);
	
	
	
	//if(true) cout<<1; cout<<2;
	
	// int arr[10][10];
	// memset(arr, -1, sizeof(arr));
	// for(int i = 0; i < 10; i++){
	// 	for(int j = 0; j < 10; j++){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	//string str = "55";
	// char c = '5';
	// int a = c-48;
	// cout<<a;
	
	// if(-1){
	// 	cout<<"음수또한 트루임"<<endl;
	// }
	
	// vector<pair<int,int>> v;
	
	// v.push_back({1,1});
	// v.push_back({2,2});
	// v[0].first += 1;
	// for(int i = 0; i < v.size(); i++){
	// 	cout<<v[i].first<<" "<<v[i].second<<endl;
	// }
	
	
	
	// set<pair<int,int>> s;
	// s.insert({100,100});
	// s.insert({100,10});
	// s.insert({50,100});
	// s.insert({50,10});
	// s.insert({10,1000});
	
	// for(auto it = s.begin(); it != s.end(); it++){
	// 	pair<int,int> p = *(it);
	// 	cout<<p.first<<" "<<p.second<<endl;
	// }
	
	
	//string str = "test";
	//cout<<str[1]<<endl;
	//if(str[0] == 't')
	//	cout<<"char";
	// if(str[0] == "t"){
	// 	cout<<"string";
	// }
	// string str = "1234";
	// int a = str[1];//2 so -48
	// cout<<a;
	return 0;
}