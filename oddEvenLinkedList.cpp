/*
Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
 
Constraints:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
The length of the linked list is between [0, 10^4].

*/

/*
APPROACH:
The below program maintains two pointers ‘odd’ and ‘even’ for current nodes at odd an even positions respectively. We also store first node of even linked list so that we can attach the even list at the end of odd list after all odd and even nodes are connected together in two different lists.
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even, *evenHead, *odd;
        if(!head)
            return NULL;
        odd = head;
        even = head->next;
        evenHead = even;
        while(1)
        {
            if(!even || !even->next)
            {
                if(even && !even->next)
                    even = even->next;
                odd->next = evenHead;
                break;
            }
            
            if(even)
            {
                odd->next = even->next;
                odd = odd->next;
                
                if(odd)
                {
                    even->next = odd->next;
                    even = even->next;
                }
            }
        }
        return head;
    }
};
