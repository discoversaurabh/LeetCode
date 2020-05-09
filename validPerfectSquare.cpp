/*
Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Output: true

Example 2:
Input: 14
Output: false
*/

class Solution {
public:
    bool perfectSquareUtil(int beg, int end, int num)
    {
        long tmp;
        if(beg > end) 
            return false;
        
        int mid = beg + (end-beg)/2;
        tmp = (long)mid*mid;
        if(tmp == (long)num)
            return true;
        else
        {
            if(tmp > (long)num)
                return perfectSquareUtil(beg, mid-1, num);
            else
                return perfectSquareUtil(mid+1, end, num); 
        }
    }
    
    bool isPerfectSquare(int num) {
        if(!num) return true;
        if(num == 1) return true;
        return perfectSquareUtil(0, num/2, num);
    }
};
