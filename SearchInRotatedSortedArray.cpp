/*
Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
class Solution {
public:

	int modifiedBinSearch(vector<int> &nums, int beg, int end, int target, bool isFindingPivot)
	{
		int a = -1;
		if (beg > end)
			return -1;

		int mid = beg + (end - beg) / 2;

		if (isFindingPivot)
		{
			//if (mid != 0 && mid != nums.size() - 1 && nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
            /*if (mid <= nums.size() - 1)
            {
                if(nums[mid] < nums[mid - 1]))
                {
                    if(mid >= 0)
                    {
                        if(nums[mid] < nums[mid + 1])
                        {
                            return mid;
                        }
                    }
                }
            }*/
            if(mid == nums.size()-1 && nums[mid] < nums[mid - 1])
            {
                return mid;
            }
            else if(mid == 0 && nums[mid] < nums[mid + 1])
            {
                return mid;
            }
            else if (mid > 0 && mid < nums.size() - 1 && nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
            {
                return mid;
            }
			else
			{
				a = modifiedBinSearch(nums, mid + 1, end, target, true);
				if (a != -1)
					return a;
				a = modifiedBinSearch(nums, beg, mid - 1, target, true);
				if (a != -1)
					return a;
			}
			return -1;
		}
		else
		{

			if (target == nums[mid])
			{
				return mid;
			}
			else
			{
				if (target < nums[mid])
				{
					return modifiedBinSearch(nums, beg, mid - 1, target, false);
				}
				else
				{
					return modifiedBinSearch(nums, mid + 1, end, target, false);
				}
			}
		}
		return -1;
	}

	int search(vector<int>& nums, int target) {
		// search for pivot first
		int beg = 0, end = nums.size() - 1;

        if (end <= 2)
		{
			for (int i = 0; i <= end; i++)
			{
				if (target == nums[i])
					return i;
			}
			return  -1;
		}
        
		int pivotIndex = modifiedBinSearch(nums, beg, end, target, true);
		if (pivotIndex == -1)
			pivotIndex = 0;
		
		if (target == nums[pivotIndex])
			return pivotIndex;
		else
		{
			// return modifiedBinSearch(nums, beg, end, target, false);
			if (target > nums[end])
			{
				return modifiedBinSearch(nums, beg, pivotIndex - 1, target, false);
			}
			else
			{
				return modifiedBinSearch(nums, pivotIndex + 1, end, target, false);
			}
		}
	}
};
