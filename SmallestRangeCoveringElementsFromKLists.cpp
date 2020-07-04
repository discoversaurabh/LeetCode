/*
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

 

Example 1:

Input: [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
 

Note:

The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.

*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int rsize = nums.size();
        if(!rsize) return {};
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;
        int minVal = INT_MAX, maxVal = INT_MIN, minDiff = INT_MAX, ans[2];
        
        for(int i=0; i<rsize; i++)
        {
            if(nums[i].size() > 0)
            {
                minHeap.push(make_pair(nums[i][0], make_pair(i,0)));
                maxVal = maxVal < nums[i][0] ? nums[i][0] : maxVal;
            }
        }
        
        while(minHeap.size() == rsize)  //Most Important condition
        {
            auto tp = minHeap.top();
            minHeap.pop();
            minVal = tp.first;
            if(minDiff > (maxVal-minVal))
            {
                minDiff = maxVal-minVal;
                ans[0] = minVal;
                ans[1] = maxVal;
            }
            
            if(tp.second.second+1 < nums[tp.second.first].size())
            {
                if( nums[tp.second.first][tp.second.second+1] > maxVal)
                    maxVal = nums[tp.second.first][tp.second.second+1];
                minHeap.push(make_pair(nums[tp.second.first][tp.second.second+1], make_pair(tp.second.first,tp.second.second+1)));
            }
        }
        
        return {ans[0], ans[1]};
    }
};
