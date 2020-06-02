/*
Permutations (https://leetcode.com/problems/permutations/)

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

#include"AllHeader.h"
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res1, res2;
		int size = nums.size();
		if (!size) return res1;

		res2.push_back({ nums[0] });

		for (int i = 1; i < size; i++)
		{
			res1.clear();
			for (int j = 0; j < res2.size(); j++)
			{
				for (int k = 0; k <= res2[j].size(); k++)    //delibrately given as equal becase it has to run 1 time more to insert number at the end too
				{
					vector<int> v = res2[j];
					v.emplace(v.begin() + k, nums[i]);
					res1.push_back(v);
				}
			}
			if (i != size - 1)
				res2 = res1;
		}
		return res1;
	}
};

int main()
{
	vector<int> arr = { 1,2,3 };
	Solution s;
	s.permute(arr);
	return 0;
}
