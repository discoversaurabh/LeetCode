/*

Search in Rotated Sorted Array

You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4

*/

class Solution {
public:
    
    int searchRec(vector<int>& nums, int beg, int end, int target)
    {
        if(beg > end)
            return -1;
        
        int mid = beg + (end-beg)/2;
        
        if(nums[mid] == target)
            return mid;
        //else if(nums[mid] == nums[beg] && nums[mid] == nums[end])   //duplicate numbers case
        //{
        //    beg++;
        //    end--;
        //}
        else if(nums[beg] <= nums[mid]) //left is sorted
        {
            if(target >= nums[beg] && target <= nums[mid])
                end = mid-1;
            else
                beg = mid+1;            //number does not lie in sorted space so move towards unsorted side.
        }
        else//(nums[mid] < nums[end])   //right is sorted
        {
            if(target >= nums[mid] && target <= nums[end])
                beg = mid+1;
            else
                end = mid-1;         //number does not lie in sorted space so move towards unsorted side.
        }
        
        return searchRec(nums, beg, end, target);
    }
    
    int search(vector<int>& nums, int target) {
        int N=nums.size();
        if(!N)
            return -1;
        return searchRec(nums, 0, N-1, target);
    }
};
