/*
Product of Array Except Self

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)    
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tmp = 1, size = nums.size();
        vector<int> result(size);
        result[0] = tmp;
        for(int i=1; i<size; i++)
        {
            result[i] = result[i-1] * nums[i-1];
            //tmp = tmp*nums[i];
            //result[i] = result[i-1] * nums[i-1];
        }
        //result[size-2] =result[i] * nums[size-1]; 
        tmp = 1;
        for(int i=size-1; i>=0; i--)
        {
            //result[i] = tmp;
            result[i] = tmp * result[i];
            tmp = tmp * nums[i];
        }
        //result[size-1] = 
        return result;
    }
};
