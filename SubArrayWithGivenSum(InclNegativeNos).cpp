/*
Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

Hide Hint #1  
Will Brute force work here? Try to optimize it.

Hide Hint #2  
Can we optimize it by using some extra space?
   Hide Hint #3  
What about storing sum frequencies in a hash table? Will it be useful?
   Hide Hint #4  
sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1. Can we use this property to optimize it.
*/

class Solution {
public:
    /* SAURABH - Sliding window method is not going to work here as we have negative numbers also (Mind it)*/
    #if 0
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int r = 0, l = 0, sum = 0, answer = 0, lastVisited = INT_MIN
        for(int r=0; r<size; ++r)
        {
            sum += nums[r];
            if(sum == k)
                answer++;
            else if(sum < k)
            {
                if(sum )
                lastVisited = nums[r];
                continue;
            }
            else
            {
                while(sum > k)
                {
                    sum -= nums[l];
                    l++;
                    if(sum == k && l != size)
                        answer++;
                    
                }
            }
        }
        return answer;
    }
    #endif
    
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int answer = 0, sum = 0;
        unordered_map<int, int> countMap;
        for(int i=0; i<size; ++i)
        {
            sum += nums[i];
            if(sum == k)
                answer++;
            if(countMap.find(sum-k) != countMap.end())
            {
                answer += countMap[sum-k];
            }
            countMap[sum]++;
        }
        return answer;
    }
};
