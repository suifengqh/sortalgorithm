#include <iostream>

using namespace std;

void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}

void InsertionSort1(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	for(int i = 1; i < size; i++){
		int j = i;
		while(j>0 && a[j] < a[j-1]){
			swap(a[j], a[j-1]);
			--j;
		}
		for(int k = 0; k < size; k++){
			cout << a[k] <<" ";
		}
		cout << endl;
	}
}

void InsertionSort2(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	for(int i = 1; i < size; i++){
		int j = i-1;
		int tmp = a[i];
		while(j>=0 && a[j] > tmp){
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = tmp;
		for(int k = 0; k < size; k++){
			cout << a[k] <<" ";
		}
		cout << endl;
	}
}

int main(){
	int a1[] = {15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
	const size_t sz1 = sizeof(a1)/sizeof(a1[0]);
	InsertionSort1(a1, sz1);
	cout << endl;

	int a2[] = {15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
	const size_t sz2 = sizeof(a2)/sizeof(a2[0]);
	InsertionSort1(a2, sz2);
	return 0;
}