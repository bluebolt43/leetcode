#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;

        RandomListNode *p = head;
        RandomListNode *tmp;
        do {
            tmp = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = tmp;
            p = tmp;
        } while(p != NULL);

        p = head;
        while(p != NULL){
            if(p->random == NULL)
                p->next->random = NULL;
            else
                p->next->random = p->random->next;
                
            p = p->next->next;
        }

        
        RandomListNode *result = head->next;

        p = head;
        tmp = result;
        while(1) {
            p->next = tmp->next;
            p = p->next;
            if(p == NULL) break;
            tmp->next = p->next;
            tmp = tmp->next;
        }

        return result;
    }
};



int main()
{
	//{0,1,5#1,2,5#2,3#3,4,4#4,5,5#5}

	RandomListNode* p0 = new RandomListNode(0);
	RandomListNode* p1 = new RandomListNode(1);
	RandomListNode* p2 = new RandomListNode(2);
	RandomListNode* p3 = new RandomListNode(3);
	RandomListNode* p4 = new RandomListNode(4);
	RandomListNode* p5 = new RandomListNode(5);
	p0->next=p1;
	p0->random=p4;
	p1->next=p2;
	p1->random=p5;
	p2->next=p3;
	p2->random=p2;
	p3->next=p4;
	p3->random=p2;
	p4->next=p5;
	p5->random=p1;
		
	Solution solution;
	RandomListNode* r = solution.copyRandomList(p0);

    RandomListNode* tmp;

	for(tmp=r;tmp!=NULL;tmp=tmp->next){
		cout <<  tmp->label << endl;
		if(tmp->next!=NULL)
			cout << " next " <<tmp->next->label<< endl;
		if(tmp->random!=NULL)
			cout << " random " <<tmp->random->label<< endl;
	}

	return 0;
}
