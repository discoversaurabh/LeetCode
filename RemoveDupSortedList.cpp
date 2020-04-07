/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = head, *cur, *tmp;
        ListNode *result = head;
        if(head)
             cur = head->next;
        else
            return NULL;
        
        while(cur)
        {
            if(cur->val != prev->val)
            {
                prev->next = cur;
                prev = cur;
                cur = cur->next;
            }
            else
            {
                cur = cur->next;
                //tmp = cur->next;
                //delete cur;
            }
            
        }
        prev->next = NULL;
        return result;
    }
};
