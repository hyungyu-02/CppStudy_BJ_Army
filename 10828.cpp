#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n, p;
string str;
int stack[10000];
int point = 0;

void push_(int num){
	stack[point] = num;
	point++;
	return;
}
void pop_(){
	if(point != 0){
		cout<<stack[point-1]<<endl;
		point--;
	}else
		cout<<-1<<endl;
	return;
}
void size_(){
	cout<<point<<endl;
	return;
}
void empty_(){
	if(point)
		cout<<0<<endl;
	else
		cout<<1<<endl;
	return;
}
void top_(){
	if(!point){
		cout<<-1<<endl;
	}
	else{
		cout<<stack[point-1]<<endl;
	}
	return;
}

int main(){
	cin>>n;
	
	while(n--){
		cin>>str;
		char* c = const_cast<char*>(str.c_str());
		if(!strcmp(c,"push")){
			cin>>p;
			push_(p);
		}
		else if(!strcmp(c,"pop")){
			pop_();
		}
		else if(!strcmp(c,"size")){
			size_();
		}
		else if(!strcmp(c,"empty")){
			empty_();
		}
		else{
			top_();
		}
	}
	
	return 0;
}