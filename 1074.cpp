#include <iostream>
#include <cmath>

using namespace std;

void findZ(int x, int y, int power);

int n, r, c;
int target = 0;

int main(){
	cin>>n>>r>>c;
	
	findZ(0, 0, n);
	//cout<<target<<endl;
	
	return 0;
}

void findZ(int x, int y, int power){
	//cout<<"findZ => x : "<<x<<" y : "<<y<<" power : "<<power<<endl;
	if(x == r && y == c)
		cout<<target<<endl;
	else{
		if(r >= x && r < x + (int)pow(2,power-1)){
			if(c >= y && c < y + (int)pow(2,power-1)){
				findZ(x + 0, y + 0, power-1);
			}
			else if(c >= y + (int)pow(2,power-1) && c < y + (int)pow(2,power)){
				target += (int)pow(2,power-1) * (int)pow(2,power-1);
				findZ(x + 0, y + (int)pow(2,power-1), power-1);
			}
		}
		else if(r >= x + (int)pow(2,power-1) && r < x + (int)pow(2,power)){
			if(c >= y && c < y + (int)pow(2,power-1)){
				target += (int)pow(2,power-1) * (int)pow(2,power-1) * 2;
				findZ(x + (int)pow(2,power-1), y + 0, power-1);
			}
			else if(c >= y + (int)pow(2,power-1) && c < y + (int)pow(2,power)){
				target += (int)pow(2,power-1) * (int)pow(2,power-1) * 3;
				findZ(x + (int)pow(2,power-1), y + (int)pow(2,power-1), power-1);
			}
		}
	}
}