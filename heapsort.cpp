#include <iostream>

using namespace std;

void print(int *a, int size) {
	if(!a) return;
	for (int i = 0; i < size; i++ ) cout << a[i] << " ";
	cout << endl;
}
void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}
void build_heap(int *a, int k, int size){
	while(2*k+1 < size){
		//对于下标从0开始的数组，左儿子下标为2k+1,右儿子下标为2k+2
		int child = 2*k+1;
		if(child+1 < size && a[child+1] > a[child]){
			++child;
		}
		if(a[k] < a[child]){
			swap(a[k], a[child]);
			k = child;
		}
		else{
			//由于是自底向上建堆，子节点已经是堆结构，直接退出
			break;
		}
	}
}
void HeapSort(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	for(int i = size/2-1; i>=0; --i){//对于下标从0开始的数组，非叶节点从size/2-1开始
		build_heap(a, i, size);
	}
	print(a, size);
	for(int i = size-1; i>0; --i){
		swap(a[0], a[i]);
		build_heap(a, 0, i);
		print(a, size);
	}
}

int main(){
	//int a[] = {13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
	int a[]={15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
	//int a[]={1, 12, 5, 26, 7, 14, 3, 7, 2};
	//int a[]={7, 7, 5, 1, 3, 2};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	HeapSort(a, sz);
	print(a, sz);
	return 0;
}
