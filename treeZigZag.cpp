#include"AllHeader.h"
/*
Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		stack<TreeNode*> st;
		stack<TreeNode*> st2;
		vector<vector<int>>result;
		vector<int>row; //Brilliant Idea - to insert in the result vector after every level completion
		bool checkEntryCondition = false;
		if (root)
		{
			st2.push(root);
			row.push_back(root->val);
			result.push_back(row);
			row.clear();
		}
		else
			return result;

		while (!st2.empty() || !st.empty())
		{
			if (st.empty())
			{
				// operate on st2
				TreeNode* tmp;
				while (!st2.empty())
				{
					tmp = st2.top();
					st2.pop();
					//insert into stack in proper fashion .. means right first
					if (tmp)
					{
						if (tmp->right)
						{
							row.push_back(tmp->right->val);
							checkEntryCondition = true;
							st.push(tmp->right);
						}
						if (tmp->left)
						{
							row.push_back(tmp->left->val);
							checkEntryCondition = true;
							st.push(tmp->left);
						}
					}
				}
				if (checkEntryCondition)
				{
					result.push_back(row);
					row.clear();
					checkEntryCondition = false;
				}
			}
			else if (st2.empty())
			{
				// operate on stack
				TreeNode* tmp;
				while (!st.empty())
				{
					// checkEntryCondition = true; // MUST NOT BE GIVEN HERE ...THINK WHY
					tmp = st.top();
					st.pop();
					//insert into queue in proper fashion .. means left first
					if (tmp)
					{
						if (tmp->left)
						{
							row.push_back(tmp->left->val);
							checkEntryCondition = true;
							st2.push(tmp->left);
						}
						if (tmp->right)
						{
							row.push_back(tmp->right->val);
							checkEntryCondition = true;
							st2.push(tmp->right);
						}
					}
				}
				if (checkEntryCondition)
				{
					result.push_back(row);
					row.clear();
					checkEntryCondition = false;

				}
			}
			else
				return result;
		}
		return result;
	}
};

TreeNode* getNode(int x)
{
	TreeNode* tmp = new TreeNode(x);
	tmp->left = tmp->right = NULL;
	tmp->val = x;
	return tmp;
}

int main()
{
	/*TreeNode* r = getNode(3);
	r->left = getNode(9);
	r->right = getNode(20);
	r->right->left = getNode(15);
	r->right->right = getNode(7);*/
	TreeNode* r = getNode(0);
	r->left = getNode(2);
	r->right = getNode(4);

	r->left->left = getNode(1);
	r->right->left = getNode(3);
	r->right->right = getNode(-1);

	r->left->left->left = getNode(5); 
	r->left->left->right = getNode(1);
	r->right->left->right = getNode(6);
	r->right->right->right = getNode(8);	//output should be [[0],[4,2],[1,3,-1],[8,6,1,5]]

	Solution s;
	s.zigzagLevelOrder(r);
	return 0;
}