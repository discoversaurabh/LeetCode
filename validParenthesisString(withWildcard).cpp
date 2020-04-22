/*
Valid Parenthesis String (with a wildcard character)

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.

'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

Note:
The string size will be in the range [1, 100].
*/

/*
APPROACH : The code works on the logic that the balanced parenthesis will be balanced from both sides i.e., from start and from end. So this logic checks for both sides individually and as soon as an imalance is found. It returns false.
A very good explanation of this method is given here :
For this approach, I decided to see whether or not I could improve it, both in terms of space and time complexity, although his solution is perfectly fine, so here is my way of getting O(2 * N) time down to O(N) and O(2 * N) space down to O(1). Hope you enjoy!

The idea behind this approach is simple. We keep two counters, each for a seperate kind of parentheses. When we encounter '(', we increment the first counter and when we encounter ')' we decrement it. The opposite is done to the second counter.

In both cases however, we increment our counters in case * is our current symbol. To illustrate it better I will first run two traversals and later merge them into a single loop. It's easy to see why in the example, so let's consider the following sequence:
*()*(()*))
First we traverse from left to right. For each position in the string our counter changes as follow:

-1 (before traversing) = 0
0 = 1
1 = 2
2 = 1
3 = 2
...
9 = 3
10 = 2
Since our final result is >= 0, we know there were at least the same number of open and closed parentheses. Were the result less than 0 (at any point), that would mean we encountered more closing parentheses than the opening ones - return false, that's an impossible sequence.

Similarly, we traverse from the end now and swap the key values for incrementation/decrementatoin.

10 (before traversing) = 0
9 = 1
8 = 2
7 = 3
...
1 = 3
0 = 4
Our result is once again >= 0, which means we encountered at least the same number of opening and closing parenthesis. Were it different (at any given point), yet again that would mean we have not closed all the opening brackets until that point.
*/

class Solution {
public:
    bool checkValidString(string s) {
        int len = s.length();
        int openCount = 0, closeCount = 0;
        for(int i=0; i<len; i++)
        {
            if(s[i] == '(' || s[i] == '*')
                openCount++;
            else
                openCount--;
            
            if(s[len-i-1] == ')' || s[len-i-1] == '*')
                closeCount++;
            else
                closeCount--;
            
            if(openCount < 0 || closeCount < 0)
                return false;
        }
        return true;
    }
};
