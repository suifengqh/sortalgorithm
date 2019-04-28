#include <iostream>

using namespace std;

void print(int *a, int sz) {
	for (int i = 0; i < sz;  i++ ) cout << a[i] << " ";
	cout << endl;
}
void ShellSort(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	for(int gap = size/2; gap>0; gap = gap/2){
		for(int i = gap; i < size; ++i){
			int j = i;
			int tmp = a[i];
			while(j-gap >= 0 && a[j-gap] > tmp){
				a[j] = a[j-gap];
				j = j-gap;
			}
			a[j] = tmp;
		}
		for(int k = 0; k < size; k++){
			cout << a[k] <<" ";
		}
		cout << endl;
	}
}

int main(){
	int a[] = {13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	ShellSort(a, sz);
	return 0;
}