#include<unordered_map>
#include<iostream>
#include<vector>
#include<algorithm>
#include<ostream>
#include<string>
#include<sstream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans = new ListNode(0);
		ListNode *t1 = l1, *t2 = l2, *ta = ans, *preNode = new ListNode(0);
		int tmp, carry = 0;
		
		while (t1 != NULL && t2 != NULL)
		{
			tmp = t1->val + t2->val + carry;
			carry = (tmp > 9 ? 1 : 0);
			ta->val = tmp % 10;

			t1 = t1->next;
			t2 = t2->next;
			ta->next = new ListNode(0);
			preNode = ta;
			ta = ta->next;
		}
		if (!t1)
		{
			while (t2)
			{
				tmp = t2->val + carry;
				carry = (tmp > 9 ? 1 : 0);
				ta->val = tmp % 10;

				t2 = t2->next;
				ta->next = new ListNode(0);
				preNode = ta;
				ta = ta->next;
			}
		}
		else if (!t2)
		{
			while (t1)
			{
				tmp = t1->val + carry;
				carry = (tmp > 9 ? 1 : 0);
				ta->val = tmp % 10;

				t1 = t1->next;
				ta->next = new ListNode(0);
				preNode = ta;
				ta = ta->next;
			}
		}

		//edge case
		if (carry)
		{
			ta->val = carry;
		}
		else
		{
			delete preNode->next;
			preNode->next = NULL;
			//ta = NULL;
		}

		return ans;
	}
};

int main()
{
#ifdef EXAMPLE1
	ListNode *l1, *l2;
	l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
#else
	ListNode *l1, *l2;
	l1 = new ListNode(5);
	l2 = new ListNode(5);
#endif
	ListNode *ans = Solution().addTwoNumbers(l1, l2);

	while (ans)
	{
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
	return 0;
}