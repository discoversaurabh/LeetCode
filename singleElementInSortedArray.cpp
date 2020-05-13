/*
Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice,
except for one element which appears exactly once.Find this single element that appears only once.

Example 1:
Input: [1, 1, 2, 3, 3, 4, 4, 8, 8]
Output : 2

Example 2 :
Input : [3, 3, 7, 7, 10, 11, 11]
Output : 10

Note : Your solution should run in O(log n) time and O(1) space.
*/
/*
SAURABH APPROACH:
The idea is to use Binary Search. 
All elements before the required have first occurrence at even index (0, 2, ..)
and next occurrence at odd index (1, 3, …). And all elements after the required element have
first occurrence at odd index and next occurrence at even index.
1) Find the middle index, say ‘mid’.
2) If ‘mid’ is even, then compare arr[mid] and arr[mid + 1]. If both are same, then the required element after ‘mid’ else before mid.
3) If ‘mid’ is odd, then compare arr[mid] and arr[mid – 1]. If both are same, then the required element after ‘mid’ else before mid.
*/
#include"AllHeader.h"
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int beg = 0, end = nums.size(), mid = 0;
		int resInd = -1;
		end--;
		while (beg <= end)
		{
			int mid = beg + (end - beg) / 2;

			if (mid == 0 || mid == end)
			{
				if (resInd != -1)
					return nums[resInd];
				else
					return nums[mid];
			}
				
			// If mid is even and element next to mid is 
			// same as mid, then output element lies on 
			// right side, else on left side 
			if (mid % 2 == 0)
			{
				if (nums[mid] == nums[mid + 1])
				{
					beg = mid + 2;
					//resInd = beg;
				}
				else
				{
					end = mid - 1;
					resInd = mid;
				}
			}
			else
			{
				// mid is odd
			}
			{
				if (nums[mid] == nums[mid - 1])
				{
					beg = mid + 1;
					//resInd = end;
				}
				else
				{
					end = mid - 1;
					resInd = end;
				}
			}
		}
		//cout<<resInd<<endl;
		return nums[resInd];
	}
};

int main()
{
	//vector<int> arr = { 1,1,2,3,3 };
	//vector<int> arr = { 1,1,2 };
	vector<int> arr = { 1,2,2,3,3 };

	Solution s;
	s.singleNonDuplicate(arr);
	return 0;
}