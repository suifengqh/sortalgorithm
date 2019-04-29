#include <iostream>
using namespace std;

class ListNode 
{ 
public:
	int val;  
	ListNode *next;
	ListNode(int _val){
		val = _val;
		next = NULL;
	} 
};

void print(int *a, int size) {
	if(!a) return;
	for (int i = 0; i < size; i++ ) cout << a[i] << " ";
	cout << endl;
}
void print(ListNode* head) {
	if(!head) return;
	while(head){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

ListNode* InsertionSort(ListNode *head){
	if(!head || !head->next){
		return head;
	}
	ListNode* dummy = new ListNode(-1);
	ListNode* cur = dummy;
	while(head){
		cur = dummy;
		ListNode* t = head->next;
		while(cur->next && cur->next->val <= head->val){
			cur = cur->next;
		}
		head->next = cur->next;
		cur->next = head;
		head = t;
	}
	return dummy->next;
}

void BucketSort(int *a, int size){
	if(!a || size <= 0){
		return;
	}
	int max = a[0];
	for(int i = 1; i < size; ++i){
		if(a[i] > max) max = a[i];
	}
	int bucket_cnt = max/10 + 1;
	ListNode **buckets = new ListNode*[bucket_cnt];
	for(int i = 0; i < bucket_cnt; ++i) {
		buckets[i] = NULL;
	}
	for(int i = 0; i < size; ++i){
		ListNode* tmp = new ListNode(a[i]);
		int pos = a[i]/10;
		tmp->next = buckets[pos];
		buckets[pos] = tmp;
	}
	cout<<"before sort for each bucket:"<<endl;
	for(int i = 0; i < bucket_cnt; ++i) {
		print(buckets[i]);
	}
	cout<<"after sort for each bucket:"<<endl;
	for(int i = 0; i < bucket_cnt; ++i) {
		buckets[i] = InsertionSort(buckets[i]);
		print(buckets[i]);
	}
	int index = 0;
	for(int i = 0; i < bucket_cnt; ++i){
		ListNode* tmp = buckets[i];
		while(tmp){
			a[index++] = tmp->val;
			tmp = tmp->next;
		}
	}

	//free memory
	for(int i = 0; i < bucket_cnt; ++i){
		ListNode* head = buckets[i];
		while(head){
			ListNode* tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	delete[] buckets;
}

int main(){
	int a[] = {13, 14, 94, 33, 82, 113, 25, 59, 94, 106, 65, 23, 125, 86, 101, 27, 73, 111, 25, 39, 120, 10, 78, 110, 23, 65, 55, 78, 4, 12};
	const size_t sz = sizeof(a)/sizeof(a[0]);
	BucketSort(a, sz);
	print(a, sz);
	return 0;
}

