#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[51];
int myParent[51];
int n, rem;
int root;
int leafs = 0;

void findLeafs(int head){
	if(!tree[head].size()){
		leafs++;
		return;
	}
	for(int i = 0; i < tree[head].size(); i++){
		findLeafs(tree[head][i]);
	}
	return;
}

int main(){
	cin>>n;
	int parent;
	for(int i = 0; i < n; i++){
		cin>>parent;
		myParent[i] = parent;
		if(parent != -1){
			tree[parent].push_back(i);
		}else{
			root = i;
		}
	}
	
	cin>>rem;
	if(rem == root){
		cout<<0;
		return 0;
	}
	
	for(auto it = tree[myParent[rem]].begin(); it != tree[myParent[rem]].end(); it++){
		if(*it == rem){
			//cout<<"**"<<tree[myParent[rem]].size()<<"**"<<endl;
			tree[myParent[rem]].erase(it);
			//cout<<"\n**"<<tree[myParent[rem]].size()<<"**"<<endl;
			break;
		}
	}
	
	findLeafs(root);
	
	cout<<leafs;
	
	return 0;
}