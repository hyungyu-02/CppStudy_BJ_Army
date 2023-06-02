#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

int t, n;
string func, Sarr;
deque<int> arr;
bool rev = false, err = false;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>t;
	
	while(t--){
		cin>>func;
		cin>>n;
		cin>>Sarr;
		
		if(n == 0){
			if(func.find("D") != string::npos){
				cout<<"error"<<endl;
			}else{
				cout<<"[]"<<endl;
			}
			continue;
		}
		
		arr.clear();
		rev = false;
		err = false;
		
		Sarr.erase(Sarr.begin());
		Sarr.erase(Sarr.end() - 1);
		
		if(n == 1){
			arr.push_back(stoi(Sarr));
		}else{
			istringstream iss(Sarr);
			string temp;
			while(getline(iss, temp, ','))
				arr.push_back(stoi(temp));
		}
		
		for(int i = 0; i < func.size(); i++){
			if(func[i] == 'R'){
				if(rev)
					rev = false;
				else
					rev = true;
			}else{
				if(arr.empty()){
					err = true;
					break;
				}else{
					if(rev){
						arr.pop_back();
					}else{
						arr.pop_front();
					}
				}
			}
		}
		if(!err){
			if(arr.empty()){
				cout<<"[]"<<endl;
			}else{
				if(rev){
					cout<<"[";
					for(auto i = arr.rbegin(); i != arr.rend() - 1; i++){
						cout<<*i<<',';
					}
					cout<<arr[0]<<"]"<<endl;
				}else{
					cout<<"[";
					for(auto i = arr.begin(); i != arr.end() - 1; i++){
						cout<<*i<<',';
					}
					cout<<*(arr.end()-1)<<"]"<<endl;
				}
			}
		}else{
			cout<<"error"<<endl;
		}
	}
	
	
	return 0;
}