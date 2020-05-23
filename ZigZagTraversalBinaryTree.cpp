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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    // stackHandling(stack<TreeNode*> &st)
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        
        stack<TreeNode*> st1, st2;
        st1.push(root);
        vector<int> res;
        while(!st1.empty() || !st2.empty())
        {
            if(!st1.empty())
            {
                while(!st1.empty())
                {
                    auto p = st1.top();
                    st1.pop();
                    res.push_back(p->val);
                    if(p->left)
                        st2.push(p->left);
                    if(p->right)
                        st2.push(p->right);
                }
                result.push_back(res);
                res.clear();
            }
            else if(!st2.empty())
            {
                while(!st2.empty())
                {
                    auto p = st2.top();
                    st2.pop();
                    res.push_back(p->val);
                    if(p->right)
                        st1.push(p->right);
                    if(p->left)
                        st1.push(p->left);
                }
                result.push_back(res);
                res.clear();
            }
            else
                break;
        }
        
        return result;
    }
};
