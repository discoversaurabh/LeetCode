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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root) return {};
        
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        vector<vector<int>> result;
        vector<int>row;
        row.push_back(root->val);
        result.push_back(row);
        row.clear();
        //bool dirR2L = true;
        while(!st1.empty() || !st2.empty())
        {
            while(!st1.empty())
            {
                //take from stack and insert in que
                TreeNode* tmp = st1.top();
                //row.push_back(tmp->val);
                st1.pop();
                
                if(tmp->right)
                {
                    st2.push(tmp->right);
                    row.push_back(tmp->right->val);
                }    
                
                if(tmp->left)
                {
                    st2.push(tmp->left);
                    row.push_back(tmp->left->val);
                }
            }
            if(row.size() >= 1)
            {
                result.push_back(row);
                row.clear();
            }
            while(!st2.empty())
            {
                //take from que and insert in stack
                TreeNode* tmp = st2.top();
                //row.push_back(tmp->val);
                st2.pop();
                if(tmp->left)
                {
                    st1.push(tmp->left);
                    row.push_back(tmp->left->val);
                }
                if(tmp->right)
                {
                    st1.push(tmp->right);
                    row.push_back(tmp->right->val);
                }
            }
            if(row.size() >= 1)
            {
                result.push_back(row);
                row.clear();
            }
        }
        return result;
        
    }
};
