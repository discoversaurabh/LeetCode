/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int,ListNode*>>> minHeap;
        
        int size = lists.size();
        if(!size) return nullptr;
        
        ListNode* answer = new ListNode();
        ListNode* crawl = answer;
        
        for(int i=0; i<size; i++)
        {
             //cout<<lists[i]->val
            if(lists[i])
                minHeap.push(make_pair(lists[i]->val, lists[i]));
        }
        
        while(!minHeap.empty())
        {
            auto tp = minHeap.top();
            minHeap.pop();
            //cout<<tp.first<<" ";
            //crawl->val = tp.first;
            crawl->next = tp.second;//new ListNode();
            crawl = crawl->next;
            
            if(tp.second->next)
                minHeap.push(make_pair(tp.second->next->val, tp.second->next));
        }
        return answer->next;
    }
};
