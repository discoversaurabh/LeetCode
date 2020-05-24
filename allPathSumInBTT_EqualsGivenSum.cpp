/*
Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
class Solution {
public:
    // very important point
    // result is passsed by reference but res is passed by value delibrately
    // passing res by reference will not produce desired result. Think about it.
    void util(vector<vector<int>> &result, vector<int> res, TreeNode* root, int sum, int target)
    {
        //if(!root) return;
        
        res.push_back(root->val);
        
        if(!root->left && !root->right && root->val+sum == target)
            result.push_back(res);
        
        if(root->left)
            util(result, res, root->left, root->val+sum, target);
        
        if(root->right)
            util(result, res, root->right, root->val+sum, target);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> result;
        vector<int> res;
        if(!root)  return result;
        util(result, res, root, 0, target);
        return result;
    }
};
