#include <iostream>
#include <string>
using namespace std;
int n;
string files[50];
bool samechar[50];

int main(){
	fill_n(samechar, 50, true);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>files[i];
	}
	
	for(int i = 0; i < files[0].size(); i++){
		for(int j = 1; j < n; j++){
			//cout<<"\ncompare files[0]["<<i<<"] : "<<files[0][i]<<" and files["<<j<<"]["<<i<<"] : "<<files[j][i]<<endl;
			if(files[0][i] != files[j][i]){
				//cout<<"\ndifferent! break this roop"<<endl;
				samechar[i] = false;
				// if(!samechar[i]){
				// 	cout<<"samechar["<<i<<"] is changed to false"<<endl;
				// }
				break;
			}
		}
	}
	
	for(int i = 0; i < files[0].size(); i++){
		if(samechar[i]){
			cout<<files[0][i];
		}else{
			cout<<"?";
		}
	}
	
	return 0;
}