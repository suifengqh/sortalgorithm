#include <iostream>

using namespace std;

void print(int *a, int sz) {
	for (int i = 0; i < sz;  i++ ) cout << a[i] << " ";
	cout << endl;
}

void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}
void SelectionSort(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	for(int i = 0; i < size-1; i++){
		int min_idx = i;
		for(int j = i+1; j<size; ++j){
			if(a[j] < a[min_idx]){
				min_idx = j;
			}
		}
		swap(a[i], a[min_idx]);
		print(a, size);
	}
}

int main(){
	int a[] = {4, 6, 9, 1, 2, 0, 8, 7, 5, 3};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	SelectionSort(a, sz);
	return 0;
}