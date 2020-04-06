/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

#include<unordered_map>
#include<iostream>
#include<vector>
#include<algorithm>
#include<ostream>
#include<string>
#include<sstream>
#include<cassert>
#include<algorithm>
using namespace std;

class Solution {
public:

	vector<int> findRange(vector<int> &nums, int beg, int end, int target)
	{
		vector<int> result(2), left(2), right(2);//nums[beg] == target
		result[0] = INT_MAX;
		result[1] = -1;

		if (beg > end)
			return result;

		if (beg == end)
		{
			if (nums[beg] == target)
			{
				result[0] = result[0] < beg ? result[0] : beg;
				result[1] = result[1] > beg ? result[1] : beg;
				//return result;
			}
			return result;
		}

		int mid = beg + (end - beg) / 2;
		if (nums[mid] < target)
		{
			return findRange(nums, mid + 1, end, target);
		}
		else if (nums[mid] > target)
		{
			return findRange(nums, 0, mid - 1, target);
		}
		if (nums[mid] == target)
		{
			result[0] = result[0] < mid ? result[0] : mid;
			result[1] = result[1] > mid ? result[1] : mid;

			left = findRange(nums, beg, mid - 1, target);
			right = findRange(nums, mid + 1, end, target);

			result[0] = result[0] < left[0] ? result[0] : left[0];
			result[1] = result[1] > right[1] ? result[1] : right[1];

		}

		return result;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int size = nums.size();
		vector<int> result = { -1,-1 };
		result = findRange(nums, 0, size - 1, target);
		if (result[0] == INT_MAX && result[1] == -1)
			result[0] = result[1] = -1;
		return result;
	}
};

int main()
{
	vector<int> vec = {5,7,7,8,8,10}, result = { -1,-1 };
	Solution s;
	result = s.searchRange(vec, 8);
	cout << "Range of target is : (" << result[0] << "," << result[1] << ")" << endl;
	return 0;
}