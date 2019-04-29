#include <iostream>
#include <vector>
using namespace std;

void print(int *a, int size) {
	if(!a) return;
	for (int i = 0; i < size; i++ ) cout << a[i] << " ";
	cout << endl;
}

void RadixSort(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	int maxVal = 0;
	for(int i = 0; i < size; i++) {
		if(a[i] > maxVal) maxVal = a[i];
	}
	int digitPosition = 1;
	int pass = 1;  // used to show the progress
	while(maxVal/digitPosition > 0) {
		vector<vector<int> > tmp(10);
		for(int i = 0; i < size; ++i){
			tmp[(a[i]/digitPosition)%10].push_back(a[i]);
		}
		int index = 0;
		for(int i = 0; i < 10; ++i){
			for(int j = 0; j < tmp[i].size(); ++j){
				a[index++] = tmp[i][j];
			}
		}

		/* at this point, a array is sorted by digitPosition-th digit */
		cout << "pass #" << pass++ << ": ";
		print(a, size);

		/* move up the digit position */
		digitPosition *= 10;
	}   
}

int main(){
	int a[] = {13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
	//int a[]={15, 9, 8, 1, 4, 11, 7, 12, 13, 6, 5, 3, 16, 2, 10, 14};
	//int a[]={5, 9, 3, 9, 10, 9, 2, 4, 13, 10};
	//int a[]={1, 12, 5, 26, 7, 14, 3, 7, 2};
	//int a[] = {13, 14, 94, 33, 82, 113, 25, 59, 94, 106, 65, 23, 125, 86, 101, 27, 73, 111, 25, 39, 120, 10, 78, 110, 23, 65, 55, 78, 4, 12};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	RadixSort(a, sz);
	print(a, sz);
	return 0;
}