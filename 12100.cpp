// for(int i = 0; i < n; i++){
// 	for(int j = 0; j < n; j++){
// 		cout<<boN[i][j]<<" ";
// 	}
// 	cout<<endl;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int board[20][20];
int maxBlock = 0; 

void maxCheck(int bo[][20]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			maxBlock = max(maxBlock, bo[i][j]);
		}
	}
	return;
}

void moveBlock(int lev, int bo[][20]){
	cout<<"\n ********************** \n now lev : "<<lev<<"\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<" "<<bo[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n ********************** \n";
	
	if(lev >= 5){
		maxCheck(bo);
		return;
	}
	bool changed = false;
	int temp[20];
	int cnt = 0;
	
	//left
	int boN[20][20];
	memset(boN, 0, sizeof(boN));
	copy(&bo[0][0], &bo[0][0] + 400, &boN[0][0]);
	for(int i = 0; i < n; i++){
		fill_n(temp, 20, 0);
		cnt = 0;
		for(int j = 0; j < n; j++){
			if(boN[i][j]){
				temp[cnt++] = boN[i][j];
			}
		}
		
		for(int j = 0; j < cnt-1; j++){
			if(temp[j] == temp[j+1]){
				temp[j] = temp[j]*2;
				temp[j+1] = 0;
				j++;
			}
		}
		copy(temp, temp+20, boN[i]);
		fill_n(temp, 20, 0);
		
		cnt = 0;
		for(int j = 0; j < n; j++){
			if(boN[i][j]){
				temp[cnt++] = boN[i][j];
			}
		}
		copy(temp, temp+20, boN[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(bo[i][j] != boN[i][j]){
				changed = true;
				break;
			}
		}
		if(changed)
			break;
	}
	if(changed)
		moveBlock(lev+1, boN);
	else
		maxCheck(bo);
	changed = false;
	
	//right
	copy(&bo[0][0], &bo[0][0] + 400, &boN[0][0]);
	for(int i = 0; i < n; i++){
		reverse(boN[i], boN[i] + n);
	}
	for(int i = 0; i < n; i++){
		fill_n(temp, 20, 0);
		cnt = 0;
		for(int j = 0; j < n; j++){
			if(boN[i][j]){
				temp[cnt++] = boN[i][j];
			}
		}
		
		for(int j = 0; j < cnt-1; j++){
			if(temp[j] == temp[j+1]){
				temp[j] = temp[j]*2;
				temp[j+1] = 0;
				j++;
			}
		}
		copy(temp, temp+20, boN[i]);
		fill_n(temp, 20, 0);
		
		cnt = 0;
		for(int j = 0; j < n; j++){
			if(boN[i][j]){
				temp[cnt++] = boN[i][j];
			}
		}
		copy(temp, temp+20, boN[i]);
	}
	for(int i = 0; i < n; i++){
		reverse(boN[i], boN[i] + n);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(bo[i][j] != boN[i][j]){
				changed = true;
				break;
			}
		}
		if(changed)
			break;
	}
	if(changed)
		moveBlock(lev+1, boN);
	else
		maxCheck(bo);
	changed = false;
	
	//up
	copy(&bo[0][0], &bo[0][0] + 400, &boN[0][0]);
	for(int j = 0; j < n; j++){
		fill_n(temp, 20, 0);
		cnt = 0;
		for(int i = 0; i < n; i++){
			if(boN[i][j]){
				temp[cnt++] = boN[i][j];
			}
		}
		for(int i = 0; i < cnt-1; i++){
			if(temp[i] == temp[i+1]){
				temp[i] = temp[i]*2;
				temp[i+1] = 0;
				i++;
			}
		}
		for(int i = 0; i < n; i++){
			boN[i][j] = temp[i];
		}
		fill_n(temp, 20, 0);
		cnt = 0;
		for(int i = 0; i < n; i++){
			if(boN[i][j]){
				temp[cnt++] = boN[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			boN[i][j] = temp[i];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(bo[i][j] != boN[i][j]){
				changed = true;
				break;
			}
		}
		if(changed)
			break;
	}
	if(changed)
		moveBlock(lev+1, boN);
	else
		maxCheck(bo);
	changed = false;
	
	//down
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			boN[n - i - 1][j] = bo[i][j];
		}
	}
	
	for(int j = 0; j < n; j++){
		fill_n(temp, 20, 0);
		cnt = 0;
		for(int i = 0; i < n; i++){
			if(boN[i][j]){
				temp[cnt++] = boN[i][j];
			}
		}
		for(int i = 0; i < cnt-1; i++){
			if(temp[i] == temp[i+1]){
				temp[i] = temp[i]*2;
				temp[i+1] = 0;
				i++;
			}
		}
		for(int i = 0; i < n; i++){
			boN[i][j] = temp[i];
		}
		fill_n(temp, 20, 0);
		cnt = 0;
		for(int i = 0; i < n; i++){
			if(boN[i][j]){
				temp[cnt++] = boN[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			boN[i][j] = temp[i];
		}
	}
	
	int temparr[20][20];
	memset(temparr, 0, sizeof(temparr));
	copy(&boN[0][0], &boN[0][0] + 400, &temparr[0][0]);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			boN[n - i - 1][j] = temparr[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(bo[i][j] != boN[i][j]){
				changed = true;
				break;
			}
		}
		if(changed)
			break;
	}
	if(changed)
		moveBlock(lev+1, boN);
	else
		maxCheck(bo);
	
	return;
}

int main(){
	memset(board, 0, sizeof(board));
	cin>>n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>board[i][j];
		}
	}
	
	moveBlock(0, board);
	
	cout<<maxBlock;
	
	return 0;
}