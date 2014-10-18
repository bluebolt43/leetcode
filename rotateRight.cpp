#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {

		if(head==NULL)
			return NULL;

		ListNode* tmp;
		ListNode* tail;

		int count;
		for(count=0, tmp=head; tmp!=NULL; tmp=tmp->next){
			count++;
			tail=tmp;
		}

		//Circle the list
		tail->next=head;

		for(count=count-k%count,tail=head; count>0; count--){
			tail=head;
			head=head->next;
		}

		//Cut circle
		tail->next=NULL;

		return head;
	}
};


int main()
{
	Solution solution;
	ListNode* a1= new ListNode(1);
	ListNode* a2= new ListNode(2);
	ListNode* a3= new ListNode(3);
	ListNode* a4= new ListNode(4);
	ListNode* a5= new ListNode(5);
	a1->next=a2;
	a2->next=a3;
	a3->next=a4;
	a4->next=a5;
	a5->next=NULL;

	ListNode* tmp;
	for(tmp=a1; tmp!= NULL; tmp=tmp->next){
		cout << tmp->val << endl;
	}
	cout << endl;

for(int i=0;i<4;i++){
	a1->next=a2;
	a2->next=a3;
	a3->next=a4;
	a4->next=a5;
	a5->next=NULL;
	tmp = solution.rotateRight(a1, i);
	for(; tmp!=NULL; tmp=tmp->next)
		cout << tmp->val << endl;
	cout << endl;
}
	return 0;
}
