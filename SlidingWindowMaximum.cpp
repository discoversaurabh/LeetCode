//idea taken from educative.io course "hacking the coding interview C++" Array section problem 2

/*

Sliding Window Maximum

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N=nums.size();
        if(!N) return {-1};
        if(k == 1) return nums;
        deque<int> dq;
        vector<int> res;
        //int l=0;
        for(int r=0; r<N; r++)
        {
            if(dq.empty())
                dq.push_back(r);
            else
            {
                while(!dq.empty() && nums[dq.back()] < nums[r])
                {
                    dq.pop_back();
                }
                dq.push_back(r);
            }
            if(r >= k-1)    
            {
                //if(r - dq.front() + 1 > k)
                if(dq.front() <= r-k)
                {
                    dq.pop_front();
                }
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
