#include <iostream>
#include <algorithm>
using namespace std;

int rgb[1001][3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); //cin과 cout의 속도를 높여줌
	
	int n;
	int price[3];
	rgb[0][0] = 0;
	rgb[0][1] = 0; 
	rgb[0][2] = 0; 
	cin>>n;
	//동적계획법
	for(int i = 1; i <= n; i++){
		cin>>price[0]>>price[1]>>price[2];
		rgb[i][0] = min(rgb[i-1][1], rgb[i-1][2]) + price[0];
		rgb[i][1] = min(rgb[i-1][0], rgb[i-1][2]) + price[1];
		rgb[i][2] = min(rgb[i-1][1], rgb[i-1][0]) + price[2];
	}
	cout<<min(rgb[n][0],min(rgb[n][1], rgb[n][2]));
	
	return 0;
}