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
	ListNode *deleteDuplicates(ListNode *head) {
		vector <int> table_val;
		int i;
		ListNode *result = NULL;
		ListNode *tmp_pt;
		ListNode *current_pt;
		if(head==NULL){
			return result;
		}
		current_pt = head;
		result = current_pt;
		tmp_pt = result;
		table_val.push_back(current_pt->val);

		for(current_pt=head->next; current_pt!=NULL; current_pt=current_pt->next){

			for(i=table_val.size();i>0;i--){
				if(table_val[i-1] == current_pt->val){
					break;
				}
			}
			if(i==0){
				table_val.push_back(current_pt->val);
				if(current_pt!=NULL){
					tmp_pt->next = current_pt;
					tmp_pt = tmp_pt->next;
				}
			}
		}
		tmp_pt->next = NULL;
		return result;
	}
};


int main()
{
	ListNode A1(1);
	ListNode A2(2);
	ListNode A3(3);
	ListNode A4(2);
	A1.next=&A2;
	A2.next=&A3;
	A3.next=&A4;
	Solution solution;
	ListNode* R = solution.deleteDuplicates(&A1);
	ListNode *current_pt;
	for(current_pt=R; current_pt!=NULL; current_pt=current_pt->next){
		cout << current_pt->val <<endl;
	}
	return 0;
}
