/*
Jump Game

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

/*
APPROACH: 
Simple approach is that we traverse sequentially and when we go from ith index to i-1 index we reduce the jump capacity by 1 of previous index if coming index value is less than previous index value and if the coming index in greater than or equal to previous one then we do not do anything.

We stop and return false when we come to know that somehow on previous index we encountered 0 so we cannot just from that index. This covers the corner case when 0th index has a zero.

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        for(int i=1; i<size; i++)
        {
            if(nums[i-1] == 0)
                return false;
            nums[i] = (nums[i-1] > nums[i]) ? (nums[i-1]-1) : nums[i]; 
        }
        return true;
    }
};
