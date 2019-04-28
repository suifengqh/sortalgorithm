#include <iostream>

using namespace std;

void print(int *a, int left, int right) {
	for (int i = left; i <= right; i++ ) cout << a[i] << " ";
	cout << endl;
}
void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}
void QuickSort(int *a, int left, int right){
	if(!a || left >= right){
		return;
	}
	int l = left;
	int r = right;
	int pivot = a[left + (right - left)/2];
	while(l<=r){
		while(a[l] < pivot) ++l;
		while(a[r] > pivot) --r;
		if(l<=r){
			swap(a[l], a[r]);
			++l;
			--r;
		}
	}
	//print(a, left, right);
	QuickSort(a, left, r);
	QuickSort(a, l, right);
}
void QuickSort(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	return QuickSort(a, 0, size-1);
}

int main(){
	//int a[] = {13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
	int a[]={15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
	//int a[]={1, 12, 5, 26, 7, 14, 3, 7, 2};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	QuickSort(a, sz);
	print(a, 0, sz-1);
	return 0;
}