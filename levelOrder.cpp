#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue <TreeNode*> node_stack;
		vector<vector<int> > result;
        TreeNode* tmp;

        int count = 0;
		int next_level_count = 0;
		int level = 0;

        if (root == NULL){
			return result;
		}

		//initialize value, adding root node into queue and incrementing count & level 
		node_stack.push(root);
		count=node_stack.size();
		result.push_back(vector<int>());

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
			result[level].push_back(tmp->val);
			node_stack.pop();
			count--;

			//When current level finish, we move to next level
			if(count==0){
				if(next_level_count!=0){
					result.push_back(vector<int>());
					count=next_level_count;
					level++;
					next_level_count=0;
				}
			}
		}

		return result;
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > tmp = levelOrder(root);
		return vector<vector<int> >(tmp.rbegin(), tmp.rend());
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
	vector<vector<int> > tmp;
    int i,j;
	tmp = solution.levelOrder(&sample);
	for(i=0;i<tmp.size();i++){
		for(j=0;j<tmp[i].size();j++)
			cout << tmp[i][j] << " ";
		cout <<endl;
	}
	tmp = solution.levelOrderBottom(&sample);
	for(i=0;i<tmp.size();i++){
		for(j=0;j<tmp[i].size();j++)
			cout << tmp[i][j] << " ";
		cout <<endl;
	}
	return 0;
}
