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
void QuickSort1(int *a, int left, int right){
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
	QuickSort1(a, left, r);
	QuickSort1(a, l, right);
}

void QuickSort2(int* a, int left, int right){
	if(!a || left>=right){
		return;
	}
	int l = left+1, r = right;
	int pivot = a[left];
	while(l<=r){
		if(a[l]>pivot && a[r]<pivot){
			swap(a[l++], a[r--]);
		}
		if(a[l]<=pivot) l++;
		if(a[r]>=pivot) r--;
	}
	swap(a[left], a[r]);
	QuickSort2(a, left, r-1);
	QuickSort2(a, r+1, right);
}

void QuickSort3(int* a, int left, int right){
	if(!a || left>=right){
		return;
	}
	int l = left, r = right-1;
	int pivot = a[right];
	while(l<=r){
		if(a[l]>pivot && a[r]<pivot){
			swap(a[l++], a[r--]);
		}
		if(a[l]<=pivot) l++;
		if(a[r]>=pivot) r--;
	}
	swap(a[l], a[right]);
	QuickSort3(a, left, l-1);
	QuickSort3(a, l+1, right);
}

void QuickSort4(int* a, int left, int right){
	if(!a || left>=right){
		return;
	}
	int i = left, j = right;
	int pivot = a[left];
	while(i!=j){
		while(i<j && a[j]>=pivot) j--;
		swap(a[i], a[j]);
		while(i<j && a[i]<=pivot) i++;
		swap(a[i], a[j]);
	}
	QuickSort4(a, left, i-1);
	QuickSort4(a, i+1, right);
}

void QuickSort(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	return QuickSort4(a, 0, size-1);
}

int main(){
	int a[] = {13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
	//int a[]={15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
	//int a[]={1, 12, 5, 26, 7, 14, 3, 7, 2};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	QuickSort(a, sz);
	print(a, 0, sz-1);
	return 0;
}