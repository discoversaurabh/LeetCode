/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    
    ListNode* reverseListRecursive(ListNode* pre, ListNode* node) {
        
        if(!node)
        {
            //head = pre;
            return pre;
        }
        
        ListNode *tmp;
        tmp = reverseListRecursive(node, node->next);
        node->next = pre;
        return tmp;
    }
    
    ListNode* reverseList(ListNode* head) {
        head = reverseListRecursive(NULL, head);
        return head;
    }
};
