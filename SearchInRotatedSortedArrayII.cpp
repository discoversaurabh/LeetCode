/*

Search in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?

*/

class Solution {
public:
    
    int searchRec(vector<int>& nums, int beg, int end, int target)
    {
        if(beg > end)
            return false;
        
        int mid = beg + (end-beg)/2;
        
        if(nums[mid] == target)
            return true;
        else if(nums[mid] == nums[beg] && nums[mid] == nums[end])   //duplicate numbers case
        {
            beg++;
            end--;
        }
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
            return false;
        return searchRec(nums, 0, N-1, target);
    }
};
