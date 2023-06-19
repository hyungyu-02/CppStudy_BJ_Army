#include <iostream>

using namespace std;

struct minHeap{
	int arr[100000];
	int endIdx = 1;
};

int n, info;
minHeap heap;

void prtAndDel(){
	if(heap.endIdx == 1){
		cout<<0<<"\n";
		return;
	}
	cout<<heap.arr[1]<<"\n";
	
	heap.arr[1] = heap.arr[heap.endIdx-1];
	heap.endIdx--;
	
	int point = 1;
	while(point*2 < heap.endIdx){
		int smallSide; //0 : left , 1 : right
		if(point*2 + 1 == heap.endIdx){
			smallSide = 0;
		}else{
			if(heap.arr[point*2] < heap.arr[point*2 + 1]){
				smallSide = 0;
			}else{
				smallSide = 1;
			}
		}
		
		if(heap.arr[point] > heap.arr[point*2 + smallSide]){
			int temp = heap.arr[point];
			heap.arr[point] = heap.arr[point*2 + smallSide];
			heap.arr[point*2 + smallSide] = temp;
			point = point*2 + smallSide;
		}else{
			break;
		}
	}
	
	return;
}
void ins(int num){
	heap.arr[heap.endIdx] = num;
	heap.endIdx++;
	
	int point = heap.endIdx-1;
	
	while(point > 1){
		if(heap.arr[point] < heap.arr[point/2]){
			int temp = heap.arr[point];
			heap.arr[point] = heap.arr[point/2];
			heap.arr[point/2] = temp;
			point = point/2;
		}else{
			break;
		}
	}
	
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>info;
		if(info){
			ins(info);
		}else{
			prtAndDel();
		}
	}
	
	return 0;
}