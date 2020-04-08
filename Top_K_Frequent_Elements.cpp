/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

#include<unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<pair<int,int>> vec;
        vector<int> result;
        result.clear();
        int size = nums.size();
        map.clear();
        
        for(int i=0; i<size; i++)
        {
            map[nums[i]]++;
        }
        
        for(auto i=map.begin(); i != map.end();++i)
        {
            vec.push_back(make_pair(i->first,i->second));
        }
        
        sort(vec.begin(), vec.end(), [](pair<int, int>a, pair<int, int>b)
             {
                 return a.second > b.second;
             });
        int j=0;
        for(auto i=vec.begin(); j<k; ++i,++j)
        {
            result.push_back(i->first);
        }
        return result;
    }
};
