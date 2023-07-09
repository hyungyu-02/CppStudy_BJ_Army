#include <iostream>
#include <string>
using namespace std;
int n;
int ans = 0;
string str;
int main(){
    cin>>n;
    cin>>str;
    for(int i = 0; i < n; i++){
        ans += str[i] - '0';
    }
    cout<<ans;
    return 0;
}