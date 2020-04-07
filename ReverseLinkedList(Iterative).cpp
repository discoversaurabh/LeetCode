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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur, *pre, *next;
        pre = NULL;
        cur = head;
        next = head ? head->next : NULL;
        
        while(cur)
        {
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next ? next->next : next;
        }
        head = pre;
        
        return head;
    }
};
