#include <iostream>

using namespace std;

void swap(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}

void BubbleSort(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	bool flag = false;
	for(int i = 0; i < size-1; i++){
		flag = false;
		for(int j = 0; j < size-1-i; j++){
			if(a[j] > a[j+1]){
				flag = true;
				swap(a[j], a[j+1]);
			}
		}
		for(int k = 0; k < size; k++){
			cout << a[k] <<" ";
		}
		cout << endl;
		if(!flag){
			break;
		}
	}
}

int main(){
	int a[] = {5, 7, 1, 3, 4, 9, 2, 6, 8, 0};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	BubbleSort(a, sz);
	return 0;
}