/*
Diameter of Binary Tree

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
class Solution {
public:
    
    int getDiaRec(TreeNode* node, int &dia)//, int &maxDepth)
    {
        if(!node)
            return 0;
        
        int l = getDiaRec(node->left, dia);//, maxDepth);
        int r = getDiaRec(node->right, dia);//, maxDepth);
        
        int tmp = l + r;
        dia = dia > tmp ? dia : tmp;
        return l > r ? l+1 : r+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        int dia = 0;//, maxDepth = 0;
        
        getDiaRec(root, dia);//, maxDepth);
        
        return dia;
    }
};
