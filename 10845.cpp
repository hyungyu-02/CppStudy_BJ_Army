#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n, p;
string str;
int queue[10000];
int point = 0;

void push_(int num){
	queue[point] = num;
	point++;
	return;
}
void pop_(){
	if(point != 0){
		cout<<queue[0]<<endl;
		for(int i = 0; i < point-1; i++){
			queue[i] = queue[i+1];
		}
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
void front_(){
	if(!point){
		cout<<-1<<endl;
	}
	else{
		cout<<queue[0]<<endl;
	}
	return;
}
void back_(){
	if(!point){
		cout<<-1<<endl;
	}
	else{
		cout<<queue[point-1]<<endl;
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
		else if(!strcmp(c,"front")){
			front_();
		}
		else{
			back_();
		}
	}
	
	return 0;
}