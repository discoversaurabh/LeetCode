/*

Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> result;
        vector<int> resRow;
        
        queue<TreeNode *> que;
        que.push(root);
        que.push(NULL);
        
        //while(que.size() > 1)  ///que.empty() check didn't work bcoz NULL entries were there, size()function ignores null entries
        while(!que.empty())
        {
            auto tp = que.front();
            que.pop();
            if(tp == NULL)
            {
                if(!que.empty())
                    que.push(NULL);
                
                result.push_back(resRow);
                resRow.clear();
            }
            else
            {
                resRow.push_back(tp->val);
            
                if(tp->left) que.push(tp->left);
                if(tp->right) que.push(tp->right);
            }
        }
        //if(!que.empty())
        //    result.push_back(resRow);
        return result;
    }
};
