/*
Subsets

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        int size = nums.size();
        if(!size) return result;

        vector<int> resUnit;
        result.push_back({});
        
        for(int i=0; i<size; i++)
        {
            int s = result.size();
            
            // We cant use result.size() in the loop here as its length is increasing inside the loop only
            // therefore it will cause the infinite loop
            // for(int j=0; j<result.size(); j++)
            
            for(int j=0; j<s; j++)
            {
                resUnit = result[j];
                resUnit.push_back(nums[i]);
                result.push_back(resUnit);
            }
        }
        return result;
    }
};
