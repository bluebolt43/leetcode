#include <iostream>
#include <queue>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};
#define BFS 1
class Solution {
public:
#if BFS
	//TODO: To apply DFS algorithm, just change the queue type to stack type.
	//However, it is complicated to get the depth.
    int maxDepth(TreeNode *root) {
        queue <TreeNode*> node_stack;
        TreeNode* tmp;

        int count = 0;
		int next_level_count = 0;
		int level = 0;

        if (root == NULL){
			return 0;
		}

		//initialize value, adding root node into queue and incrementing count & level 
		node_stack.push(root);
		count=node_stack.size();
		level++;

		while(count>0){
			//Check first node in queue and remove it
			tmp=node_stack.front();
			if(tmp->right != NULL){
				node_stack.push(tmp->right);
				next_level_count++;
			}
			if(tmp->left != NULL){
				node_stack.push(tmp->left);
				next_level_count++;
			}
			node_stack.pop();
			count--;

			//When current level finish, we move to next level
			if(count==0){
				if(next_level_count!=0){
					count=next_level_count;
					level++;
					next_level_count=0;
				}
			}
		}

		return level;
    }
#else
	//recursive
    int maxDepth(TreeNode *root) {
		int left_level=0, right_level=0;

        if (root == NULL){
			return 0;
		}

		right_level = maxDepth(root->right) + 1;
		left_level = maxDepth(root->left) + 1;

		if(right_level > left_level)
			return right_level;
		else
			return left_level;
    }
#endif
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
    int i;
	i = solution.maxDepth(&sample);
	cout << i << endl;

	return 0;
}
