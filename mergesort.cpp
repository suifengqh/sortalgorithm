#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& a) {
	for (int i = 0; i < a.size();  i++ ) cout << a[i] << " ";
	cout << endl;
}

vector<int> merge(vector<int>& left, vector<int>& right){
	vector<int> res;
	int m = left.size();
	int n = right.size();
	int i = 0, j = 0;
	while(i < m || j < n){
		if(i < m && j < n){
			if(left[i] < right[j]){
				res.push_back(left[i]);
				++i;
			}
			else{
				res.push_back(right[j]);
				++j;
			}
		}
		else{
			if(i < m){
				for(int k = i; k < m; ++k){
					res.push_back(left[k]);
				}
				break;
			}
			else if(j < n){
				for(int k = j; k < n; ++k){
					res.push_back(right[k]);
				}
				break;
			}
		}
	}
	print(res);
	return res;
}

vector<int> MergeSort(vector<int>& a){
	if(a.size() <= 1){
		return a;
	}
	vector<int> left, right, res;
	int middle = ((int)a.size()+ 1) / 2;

	for (int i = 0; i < middle; i++) {
		left.push_back(a[i]);
	}

	for (int i = middle; i < (int)a.size(); i++) {
		right.push_back(a[i]);
	}

	left = MergeSort(left);
	right = MergeSort(right);
	res = merge(left, right);

	return res;
}

int main(){
	vector<int> v;

	v.push_back(13);
	v.push_back(14);
	v.push_back(94);
	v.push_back(33);
	v.push_back(82);
	v.push_back(25);
	v.push_back(59);
	v.push_back(94);
	v.push_back(65);
	v.push_back(23);
	v.push_back(45);
	v.push_back(27);
	v.push_back(73);
	v.push_back(25);
	v.push_back(39);
	v.push_back(10);
	v = MergeSort(v);

	print(v);
	return 0;
}