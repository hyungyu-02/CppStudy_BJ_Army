//우선순위큐 (우선순위가 높은 데이터부터 pop)
#include <iostream>
#include <limits.h>
#include <string>
#include <unistd.h>

using namespace std;

struct dpq{
	int val; dpq* next{nullptr}; dpq* before{nullptr};
};

int t, k;
char order;
int info;
int data;
dpq* head;
int siz = 0;

void inputF(dpq* pnt, int num){
	if(pnt->next == nullptr){
		dpq* temp = new dpq;
		temp->val = num;
		temp->before = pnt;
		pnt->next = temp;
		return;
	}
	if(pnt->next->val >= num){
		dpq* temp = new dpq;
		temp->val = num;
		temp->before = pnt;
		temp->next = pnt->next;
		pnt->next = temp;
		temp->next->before = temp;
		return;
	}else{
		inputF(pnt->next, num);
	}
	return;
}
void deleteF(int HorT){
	if(HorT == 1){
		dpq* strm = head;
		for(int i = 0; i < siz-1; i++){
			strm = strm->next;
		}
		delete strm->next;
		strm->next = nullptr;
	}else{
		if(siz > 1){
			head->next = head->next->next;
			delete head->next->before;
			head->next->before = head;
		}else{
			delete head->next;
			head->next = nullptr;
		}
	}
	return;
}
void delMem(dpq* pnt){
	dpq* temp = pnt;
	if(temp->next != nullptr){
		delMem(temp->next);
	}
	delete pnt;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	head = new dpq;
	head->val = INT_MIN;
	
	cin>>t;
	while(t--){
		head->next = nullptr;
		siz = 0;
		cin>>k;
		while(k--){
			cin>>order;
			cin>>info;
			if(order == 'I'){
				inputF(head, info);
				siz++;
			}else{
				if(siz > 0){
					deleteF(info);
					siz--;
				}
			}
		}
		if(siz == 0){
			cout<<"EMPTY"<<endl;
		}else{
			dpq* temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			cout<<temp->val<<" ";
			cout<<head->next->val<<endl;
		}
		if(siz > 0)
			delMem(head->next);
	}
	delete head;
	return 0;
}