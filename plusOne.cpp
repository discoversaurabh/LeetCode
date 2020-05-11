/*
Plus One

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int orgSize = digits.size(), newSize = 0;
        bool isAll9 = false;
        for(auto &d : digits)
        {
            if(d == 9)
            {
                newSize++;
            }
            else
                break;
        }
        if(newSize == orgSize)  //means all 9
        {
            isAll9 = true;
            newSize++;
        }
        else
        {
            for(int i=orgSize-1; i>=0; i--)
            {
                if(digits[i] == 9 )
                    digits[i] = 0;
                else
                {
                    digits[i]++;
                    return digits;
                }
                    
            }
        }
        
        vector<int> result(newSize, 0);
        result[0] = 1;
        return result;
    }
};
