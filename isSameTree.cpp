#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        vector <TreeNode*> node_stack_p, node_stack_q;
        TreeNode *tmp_p, * tmp_q;

        if(p == NULL && q==NULL)
			return true;
		else if(p == NULL || q==NULL)
			return false;

        node_stack_p.push_back(p);
        node_stack_q.push_back(q);

		while(!node_stack_p.empty()){
			tmp_p = node_stack_p.back();
			tmp_q = node_stack_q.back();

			//Check current node value

			if(tmp_p->val != tmp_q->val){
				return false;
			}

			node_stack_p.pop_back();
			node_stack_q.pop_back();
				
			//Check current node left child
			if(tmp_p->left != NULL && tmp_q->left != NULL){
				node_stack_p.push_back(tmp_p->left);
				node_stack_q.push_back(tmp_q->left);
			}else if(tmp_p->left != NULL || tmp_q->left != NULL){
				return false;
			}

			//Check current node right child
			if(tmp_p->right != NULL && tmp_q->right != NULL){
				node_stack_p.push_back(tmp_p->right);
				node_stack_q.push_back(tmp_q->right);
			}else if(tmp_p->right != NULL || tmp_q->right != NULL){
				return false;
			}

		}

		return true;
    }
};

int main()
{
	TreeNode sample, left, l_r, right;
	sample.val = 1;
	sample.left = &left;
	sample.right = &right;
	left.val= 2;
	left.left = NULL;
	left.right = &l_r;
	right.val = 3;
	right.left = NULL;
	right.right = NULL;
	l_r.val = 4;
	l_r.left = NULL;
	l_r.right = NULL;
		
	Solution solution;
	cout << solution.isSameTree(&sample, &sample)<<endl;
	cout << solution.isSameTree(NULL, NULL)<<endl;
	return 0;
}
