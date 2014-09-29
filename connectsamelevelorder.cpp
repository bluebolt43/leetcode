#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue <TreeLinkNode*> node_stack;
        TreeLinkNode* tmp;

        int count = 0;
		int next_level_count = 0;

        if (root == NULL){
			return;
		}

		//initialize value, adding root node into queue and incrementing count & level 
		node_stack.push(root);
		count=node_stack.size();

		while(count>0){
			//Check first node in queue and remove it
			tmp=node_stack.front();
			if(tmp->left != NULL){
				node_stack.push(tmp->left);
				next_level_count++;
			}
			if(tmp->right != NULL){
				node_stack.push(tmp->right);
				next_level_count++;
			}
			node_stack.pop();
			tmp->next=node_stack.front();
			count--;

			//When current level finish, we move to next level
			if(count==0){
			    tmp->next=NULL;
				if(next_level_count!=0){
					count=next_level_count;
					next_level_count=0;
				}
			}
		}
    }
};



int main()
{
	TreeLinkNode sample(1), left(2), l_r(4), right(3);
	sample.left = &left;
	sample.right = &right;
	left.left = &l_r;

		
	Solution solution;
	TreeLinkNode *tmp, *level;
	solution.connect(&sample);
	for(tmp=&sample;tmp!=NULL;tmp=tmp->left){
		for(level=tmp;level!=NULL;level=level->next){
			cout << level->val << " ";
		}
		cout <<endl;
	}

	return 0;
}
