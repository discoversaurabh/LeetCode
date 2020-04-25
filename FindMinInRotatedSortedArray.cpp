/*
 Find Minimum in Rotated Sorted Array
 
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.
You may assume no duplicate exists in the array.

Example 1:
Input: [3,4,5,1,2] 
Output: 1

Example 2:
Input: [4,5,6,7,0,1,2]
Output: 0

*/

class Solution {
public:
    int size, answer;
        
    void findPivot(int beg, int end, vector<int> &nums)
    {
        if(beg > end)
            return;
        int mid = beg + (end-beg)/2;
        if(mid > 0)
        {
            //if(mid == 0)
            //{
                //if(nums[mid+1] < nums[mid])
                //{
                //    answer = mid
                //}
            //}
            if( mid == size-1)
            {
                //last element probably
                if(nums[mid-1] > nums[mid])
                    answer = nums[mid];//answer < mid ? answer : mid;
            }
            else
            {
                if(nums[mid-1] > nums[mid] && nums[mid+1] > nums[mid])
                    answer = nums[mid];   //answer < mid ? answer : mid;
                else
                {
                    // This extra condition was creating trouble - SAURABH
                    //if(nums[mid-1] < nums[mid] && nums[mid+1] > nums[mid])
                    //{
                        findPivot(beg, mid-1, nums);
                        findPivot(mid+1, end, nums);
                   // }
                }
                    
            }
        }
        else if(mid == 0 && size > 1)
        {
            if(nums[mid] > nums[mid+1])
                answer = nums[mid+1];
        }
    }
    
    int findMin(vector<int>& nums) {
        size = nums.size();
        if(size == 1)
            return nums[0];
        answer = INT_MAX;
        findPivot(0, size-1, nums);
        if(answer == INT_MAX)
            return nums[0];
        return answer;
    }
};
