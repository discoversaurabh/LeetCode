/*
Reverse Linked List II

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int d=1;
        ListNode *pCrawl = head, *prevH = NULL;
        while(d<m && pCrawl)
        {
            d++;
            prevH = pCrawl;
            pCrawl = pCrawl->next;
        }
        if(!pCrawl)
            return head;
        
        ListNode *end = pCrawl;
        ListNode *pre = NULL, *cur = pCrawl;
        ListNode *next = cur->next;
        
        while(d <= n && cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            d++;
        }
        if(end)
            end->next = next;
        
        if(!prevH)
            head = pre;
        else
            prevH->next = pre;
        
        return head;
    }
};
