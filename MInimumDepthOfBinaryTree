/*
Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int result = 1;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            while(t)
            {
                if(!t->left && !t->right) return result;
                else
                {
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                }
                t = q.front();
                q.pop();
            }
            if(!t)
            {
                result++;
                if(q.empty()) return result; 
                q.push(NULL);
                
            }
        }
        return result;
    }
};
