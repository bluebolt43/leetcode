#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode *first, *second;

		first = head;
		second = head;

		while(first!=NULL && second!=NULL){
			if(first->next == NULL){
				return false;
			}else{
				first = first->next->next;
			}
			second = second->next;

			if(first == second)
				if(first!=NULL)
					return true;
		}
		return false;        
    }
    ListNode *detectCycle(ListNode *head) {
		ListNode *first, *second;
		bool hascycle = false;
		first = head;
		second = head;

		while(first!=NULL && second!=NULL){
			if(first->next == NULL){
				hascycle = false;
				break;
			}else{
				first = first->next->next;
			}
			second = second->next;

			if(first == second){
				if(first!=NULL){
					hascycle = true;
					break;
				}
			}
		}

		if(hascycle==false)
			return NULL;

		first=head;
		while(first!=second){
			first=first->next;
			second = second->next;
		}
		return first;
    }
};

int main()
{
	ListNode L(1);
	//L.ListNode;
	Solution solution;
	cout << solution.hasCycle(&L) <<endl;
	ListNode* R = solution.detectCycle(&L);
	cout << R <<endl;
	return 0;
}
