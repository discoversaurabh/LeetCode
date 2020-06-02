/*
Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        int numSize = nums.size();
        if(!numSize)
            return result;
        
        result.push_back({});
        vector<int> resElement;
        
        sort(nums.begin(), nums.end());
        int lastSize, lastIndex = 0;
        
        for(int i=0; i<numSize; i++)
        {
            lastSize = result.size();
            
            for(int j=lastIndex; j<lastSize; j++)
            {
                resElement = result[j];
                resElement.push_back(nums[i]);
                result.push_back(resElement);
            }
            
            if(i+1 < numSize && nums[i+1] == nums[i])
                lastIndex = lastSize;
            else
                lastIndex = 0;
        }
        return result;
    }
};
