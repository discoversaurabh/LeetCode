/*
Contiguous Array

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int sum = 0, maxLength = 0;
        unordered_map<int, int> mp;
        mp[0] = -1; //imporantant test case as zero needs to be compared on first entry as well
        for(int i=0; i < nums.size(); ++i)
        {
            sum += (nums[i] ? 1 : -1);
            if(mp.find(sum) != mp.end())
            {
                maxLength = maxLength > (i - mp[sum]) ? maxLength : (i - mp[sum]);
            }
            else
                mp[sum] = i;
        }
        return maxLength;
    }
};
