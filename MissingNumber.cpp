/*

Missing Number
Easy

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        if(!N) return 0;
        int pos0 = -1;
        for(int i=0; i<N ; i++)
        {
            while(nums[i] != i+1 && nums[i] != 0)
            {
                swap(nums[i], nums[nums[i]-1]);
            }
            if(!nums[i]) pos0 = i+1;
        }
        return (pos0 == -1) ? 0 : pos0;
    }
};
