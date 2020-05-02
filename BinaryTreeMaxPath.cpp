/*
Binary Tree Maximum Path Sum

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

	   1
	  / \
	 2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
	/  \
   15   7

Output: 42
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include"AllHeader.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int maxSum = INT_MIN;
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	int maxPathSumUtil(TreeNode* root)
	{
		if (!root)
			return 0;

		int left = maxPathSumUtil(root->left);
		int right = maxPathSumUtil(root->right);
		int m = max(root->val, max(left, right) + root->val);

		int tmp = root->val + left + right;
		maxSum = max(maxSum, max(tmp, m));
		return m;   // as in recursion only either left or right value will go to parent
	}
	int maxPathSum(TreeNode* root) {
		if (!root)
			return 0;
		maxPathSumUtil(root);
		return maxSum;
	}
};

int  main()
{
	TreeNode *tn = new TreeNode(-10);
	tn->left = new TreeNode(9);
	tn->right = new TreeNode(20);
	tn->right->left = new TreeNode(15);
	tn->right->right = new TreeNode(7);

	Solution s;
	s.maxPathSum(tn);
	cout<<"Max Sum Path :" << s.maxSum <<endl;
	return 0;
}