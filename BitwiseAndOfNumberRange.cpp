/*
Bitwise AND of Numbers Range

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: [5,7]
Output: 4

Example 2:
Input: [0,1]
Output: 0
*/
/*
APPROACH:
follow following steps.
1) Find position of Most Significant Bit (MSB) in both numbers.
2) If positions of MSB are different, then result is 0.
3) If positions are same. Let positions be msb_p.
……a) We add 2msb_p to result.
……b) We subtract 2msb_p from x and y,
……c) Repeat steps 1, 2 and 3 for new values of x and y.

Example 1 :
x = 10, y = 20
Result is initially 0.
Position of MSB in x = 3
Position of MSB in y = 4
Since positions are different, return result.

Example 2 :
x = 17, y = 19
Result is initially 0.
Position of MSB in x = 4
Position of MSB in y = 4
Since positions are same, we compute 24.

We add 24 to result. 
Result becomes 16.

We subtract this value from x and y.
New value of x  = x - 24  = 17 - 16 = 1
New value of y  = y - 24  = 19 - 16 = 3

Position of MSB in new x = 1
Position of MSB in new y = 2
Since positions are different, we return result.
*/
class Solution {
public:
    int answer;
    int getMSB(int n)
    {
        int ind=-1;
        while(n)
        {
            n = n >> 1;
            ind++;
        }
        return ind;
    }
    int rangeBitwiseAnd(int m, int n) {
        int pos1, pos2;
        int tmp;
        answer = 0;
        while(m && n)
        {
            pos1 = getMSB(m);
            pos2 = getMSB(n);
            if(pos1 != pos2)
                return answer;
            else
            {
                tmp = 1 << pos1;
                answer += tmp;
                m -= tmp;
                n -= tmp;
            }
        }
        return answer;
    }
};
