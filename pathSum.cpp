#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL){
			return false;
		}
		
		int val = sum - root->val;
		if(val==0 & root->right==NULL & root->left==NULL){
				return true;
		}

		bool result = false;
		if(root->right!=NULL){
			result = hasPathSum(root->right, val);
		}
		if(result == false){
			if(root->left!=NULL){
				result = hasPathSum(root->left, val);
			}
		}
		return result;
    }
};

int main()
{
	TreeNode* t1= new TreeNode(1);
	TreeNode* t2= new TreeNode(2);
	TreeNode* t3= new TreeNode(3);
	TreeNode* t4= new TreeNode(4);		
	t1->left=t2;
	
	Solution solution;
    int i;
	i = solution.hasPathSum(t1,3);
	cout << i << endl;

	return 0;
}
