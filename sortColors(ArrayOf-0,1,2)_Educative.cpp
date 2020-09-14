/*

Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:

Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?
 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N=nums.size();
        if(!N) return;
        int i0=0, i1=0, i2=N-1; //0, 1 and 2 starting indexes
        while(i1 <= i2) //<= because we need to check the last index number too
        {
            if(!nums[i1])
            {
                swap(nums[i0++], nums[i1++]);
            }
            else if(nums[i1] == 1)
            {
                ++i1;
            }
            else    //2
                swap(nums[i1], nums[i2--]);
        }
    }
};
