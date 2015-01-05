#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result, *result_pt = NULL, *l1_pt, *l2_pt;
        int carrier;
        for(carrier=0, l1_pt=l1, l2_pt=l2; (l1_pt!=NULL) | (l2_pt!=NULL) | carrier;){
			int sum = carrier;
			carrier = 0;
			if(l1_pt != NULL){
				sum += l1_pt->val;
				l1_pt=l1_pt->next;
			}
			if(l2_pt != NULL){
				sum += l2_pt->val;
				l2_pt=l2_pt->next;
			}
			if(sum/10){
				carrier = sum/10;
				sum %= 10;
			}
			if(result_pt == NULL){
				result = new ListNode(sum);
				result_pt = result;
			}else{
				result_pt->next = new ListNode(sum);
				result_pt = result_pt->next;
			}

		}
        return result;
    }
};

int main()
{
	ListNode *l1, *l2, *tmp;
	l1 = new ListNode(5);
	//l1->next = new ListNode(3);
	l2 = new ListNode(5);
	//l2->next = new ListNode(4);

	Solution solution;
	tmp = solution.addTwoNumbers(l1,l2);
	for(int i=0;i<2;i++,tmp=tmp->next)
		cout << tmp->val << " ";
	cout <<endl;
	return 0;
}
