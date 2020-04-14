/*
Perform String Shifts

You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

Example 1:
Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"

Example 2:
Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 

Constraints:
1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100

*/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left = 0, right = 0, len = s.length();
        string ret;
        
        for(int i=0; i<shift.size(); ++i)
        {
            for(int j=0; j<2; j+=2)
            {
                if(shift[i][j] == 0)
                {
                    left += shift[i][j+1];
                }
                else
                    right += shift[i][j+1];
            }
        }
        ret.clear();    //imp to reset a string
        if(left > right)
        {
            left = left - right;
            if(left > len)
            {
                left = left % len;
            }
            for(int i=left;i <len;++i)
            {
                ret += s[i];
            }
            for(int i=0;i <left;++i)
            {
                ret += s[i];
            }
            return ret;
        }
        else if (right>left)
        {
            right = right - left;// - right;
            if(right > len)
            {
                right = right % len;
            }
            for(int i=len-right;i <len;++i)
            {
                ret += s[i];
            }
            for(int i=0;i <len-right;++i)
            {
                ret += s[i];
            }
            return ret;
        }
        else
        {
            return s;
        }
    }
};
