/*
Cousins in Binary Tree

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 
Note:
The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
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
    bool isFound1=false, isFound2=false;
    int parent1, parent2;
    int level1, level2;

    bool isCousinsUtil(TreeNode* root, int x, int y, int level, TreeNode *parent)
    {
        if(!root)
            return false;
        
        if(root->val == x)
        {
            if(!parent) return false;   //as this means root
            parent1 = parent->val; 
            isFound1 = true;
            level1 = level;
        }
        if(root->val == y)
        {
            if(!parent) return false;   //as this means root
            parent2 = parent->val;
            isFound2 = true;
            level2 = level;
        }
        
        if(isFound1 && isFound2){
            if(level1 != level2 || parent1 == parent2)
                return false;
            else
                return true;
        }
         
        return isCousinsUtil(root->left, x, y, level+1, root) ||
            isCousinsUtil(root->right, x, y, level+1, root);
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        return isCousinsUtil(root, x, y, 0, NULL);
    }
};
