/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	bool checkBST(TreeNode* root, long min, long max)
	{
		if (!root)
			return true;

		if (root->val > min && root->val < max)
		{
			return checkBST(root->left, min, root->val) && checkBST(root->right, root->val, max);
		}
		return false;
	}

	bool isValidBST(TreeNode* root) {
		return checkBST(root, (long)INT_MIN-1, (long)INT_MAX+1);
	}


};
