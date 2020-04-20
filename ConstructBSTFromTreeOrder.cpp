/*
Construct Binary Search Tree from Preorder Traversal

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Note: 
1 <= preorder.length <= 100
The values of preorder are "distinct".
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
    
    TreeNode* getNewNode(int val)
    {
        TreeNode *tmp = new TreeNode();
        tmp->left = tmp->right = NULL;
        tmp->val = val;
        return tmp;
    }
    
    void insertInBST(TreeNode *node, int val)
    {
        if(val > node->val)
        {
            if(node->right == NULL)
            {
                node->right = getNewNode(val);
                return;
            }
            else
                insertInBST(node->right, val);
        }
        else
        {
            if(node->left == NULL)
            {
                node->left = getNewNode(val);
                return;
            }
            else
                insertInBST(node->left, val);
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int size = preorder.size(), index=0;
        
        if(!size) return NULL;
        
        TreeNode* root = getNewNode(preorder[index]);
        
        if(size == 1)
            return root;
        
        for(int i=1; i<size;i++)
        {
            insertInBST(root, preorder[i]);
        }
        
        return root;
    }
};
