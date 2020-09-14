/*

Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.

*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int N = strs.size();
        
        unordered_map<string, vector<string>> freq;
        vector<vector<string>> ans;
        string temp;
        
        for(int i=0; i<N; i++)
        {
            temp = strs[i];   
            sort(temp.begin(), temp.end());
            freq[temp].push_back(strs[i]);
        }
        
        for(auto &f:freq)
        {
            ans.push_back(f.second);    
        }
        return ans;
    }
};
