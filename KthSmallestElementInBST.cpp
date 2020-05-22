/**
Kth Smallest Element in a BST

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Constraints:
The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
   
Hide Hint #1  
Try to utilize the property of a BST.

Hide Hint #2  
Try in-order traversal. (Credits to @chan13)

Hide Hint #3  
What if you could modify the BST node's structure?

Hide Hint #4  
The optimal runtime complexity is O(height of BST).

*/

/* 
 EASY SOLUTION : FOR UNDERSTANDING PURPOSE (OR TAKE CLASS VARIABLE OR GLOBAL VARIABLE)
 
 class Solution {
public:
    void inorder(TreeNode* root, vector<int> &res){
        if(!root)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right,res);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        vector<int> arr;
        inorder(root, arr);
        return arr[k-1];

    }
};

*/
 
class Solution {
public:
    
    TreeNode* kthSmallestUtil(TreeNode *root, int k, int &count)
    {
        if(!root) return NULL;
        
        TreeNode* tmp;
        tmp = kthSmallestUtil(root->left, k, count);
        
        if(tmp)
            return tmp;//->val; //return if already found

        count = count+1;
        if(count == k)
            return root;    //return when found
        
        tmp = kthSmallestUtil(root->right, k, count);
        return tmp;
        //if(tmp)
        //    return tmp;//->val;
       // return NULL;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* res;
        int count = 0;
        res = kthSmallestUtil(root, k, count);
        //if(!res) return -1;
        return res->val;
    }
};

/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
