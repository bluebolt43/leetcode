#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};
#define ITER 0
#define PREORDER 0
#define INORDER 0
#define POSTORDER 1
class Solution {
public:
#if ITER
    vector<int> orderTraversal(TreeNode *root) {
        vector <int> result;
        vector <int> tmp;
        int i;
        if (root == NULL){
			return result;
		}
#if PREORDER
		result.push_back(root->val);
#endif
        tmp = orderTraversal(root->left);
        for(i=0;i<tmp.size();i++)
			result.push_back(tmp.at(i));
#if INORDER
		result.push_back(root->val);
#endif
        tmp = orderTraversal(root->right);
        for(i=0;i<tmp.size();i++)
			result.push_back(tmp.at(i));
#if POSTORDER
		result.push_back(root->val);
#endif
        return result;
    }
#else
    vector<int> orderTraversal(TreeNode *root) {
        vector <int> result;
        vector <TreeNode*> node_stack;
        TreeNode *tmp, *tmp1, *tmp2;
        if(root == NULL)
			return result;
        node_stack.push_back(root);
		while(!node_stack.empty()){
#if PREORDER
			tmp = node_stack.back();
			result.push_back(tmp->val);
			node_stack.pop_back();
			if(tmp->right != NULL)
				node_stack.push_back(tmp->right);
			if(tmp->left != NULL)
				node_stack.push_back(tmp->left);
			//cout << result.back() << " ";
#endif
#if INORDER
			tmp = node_stack.back();
			node_stack.pop_back();
			if(tmp->right != NULL){
				node_stack.push_back(tmp->right);
				tmp->right = NULL;
			}
			if(tmp->left != NULL){
				tmp1 = tmp->left;
				tmp->left = NULL;
				node_stack.push_back(tmp);
				node_stack.push_back(tmp1);
			}else{
				result.push_back(tmp->val);
				//cout << result.back() << " ";
			}
#endif
#if POSTORDER
			tmp = node_stack.back();
			node_stack.pop_back();
			tmp1 = tmp->right;
			tmp2 = tmp->left;

			if(tmp1 != NULL || tmp2 != NULL){
				tmp->right = NULL;
				tmp->left = NULL;
				node_stack.push_back(tmp);
			}else{
				result.push_back(tmp->val);
				//cout << result.back() << " ";
			}
			if(tmp1 != NULL){
				node_stack.push_back(tmp1);
			}
			if(tmp2 != NULL){
				node_stack.push_back(tmp2);
			}
#endif
		}
        return result;
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
	vector <int> tmp;
    int i;
	tmp = solution.orderTraversal(&sample);
	for(i=0;i<tmp.size();i++)
		cout << tmp.at(i) << " ";
	cout <<endl;
	return 0;
}
