#include <iostream>

using namespace std;

void print(int *a, int size) {
	if(!a) return;
	for (int i = 0; i < size; i++ ) cout << a[i] << " ";
	cout << endl;
}

void CountionSort(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	int min = a[0];
	int max = a[0];
	for(int i = 1; i < size; ++i){
		if(a[i] < min) min = a[i];
		if(a[i] > max) max = a[i];
	}
	int k = max-min+1;
	int *B = new int[k];
	for(int i = 0; i < k; ++i){
		B[i] = 0;
	}
	for(int i = 0; i < size; ++i){
		B[a[i]-min]++;
	}
	int index = 0;
	for(int i = min; i <= max; ++i){
		for(int j = 0; j < B[i-min]; ++j){
			a[index++] = i;
		}
	}
	delete[] B;
}

int main(){
	//int a[] = {13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
	//int a[]={15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
	//int a[]={5, 9, 3, 9, 10, 9, 2, 4, 13, 10};
	int a[]={1, 12, 5, 26, 7, 14, 3, 7, 2};
	//int a[]={7, 7, 5, 1, 3, 2};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	CountionSort(a, sz);
	print(a, sz);
	return 0;
}