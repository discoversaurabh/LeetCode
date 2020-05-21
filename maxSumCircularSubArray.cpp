/*
Maximum Sum Circular Subarray

Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
   Hide Hint #1  
For those of you who are familiar with the Kadane's algorithm, think in terms of that. For the newbies, Kadane's algorithm is used to finding the maximum sum subarray from a given array. This problem is a twist on that idea and it is advisable to read up on that algorithm first before starting this problem. Unless you already have a great algorithm brewing up in your mind in which case, go right ahead!
   Hide Hint #2  
What is an alternate way of representing a circular array so that it appears to be a straight array? Essentially, there are two cases of this problem that we need to take care of. Let's look at the figure below to understand those two cases:

   Hide Hint #3  
The first case can be handled by the good old Kadane's algorithm. However, is there a smarter way of going about handling the second case as well?
*/

/*
APPROACH:
Intuition
I guess you know how to solve max subarray sum (without circular).
If not, you can have a reference here: 53. Maximum Subarray

Explanation
So there are two case.
Case 1. The first is that the subarray take only a middle part, and we know how to find the max subarray sum.
Case2. The second is that the subarray take a part of head array and a part of tail array.
We can transfer this case to the first one.
The maximum result equals to the total sum minus the minimum subarray sum.

So the max subarray circular sum equals to
max(the max subarray sum, the total sum - the min subarray sum)

Corner case
Just one to pay attention:
If all numbers are negative, maxSum = max(A) and minSum = sum(A).
In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
According to the deacription, We need to return the max(A), instead of sum of am empty subarray.
So we return the maxSum to handle this corner case.

Complexity
One pass, time O(N)
No extra space, space O(1)
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, min_so_far=A[0], min_ending_here = 0, max_so_far = A[0], max_ending_here = 0;
        for(auto &a:A)
        {
            min_ending_here = min(min_ending_here+a, a);
            min_so_far = min(min_ending_here, min_so_far);
            
            max_ending_here = max(max_ending_here+a, a);
            max_so_far = max(max_so_far, max_ending_here);
            
            total += a;
        }
        return max_so_far > 0 ? max(max_so_far, total-min_so_far):max_so_far;
        //vector<int> AA(A.begin(), A.end());
        //int result=INT_MIN, size = A.size();
        //int max_so_far = INT_MIN, max_ending_here = INT_MIN;
        //unordered_set<int> isTaken;
        //if(!size) return 0;
        //for(int i=0; i<size; i++)
        //    AA.push_back(A[i]);
        //
        ////for(int i=0; i<AA.size(); i++)
        //for(int i=0; i<size*2; i++)
        //{
        //    if (max_ending_here+AA[i] > AA[i] && isTaken.find(i%size) == isTaken.end())
        //    {
        //        isTaken.insert(i);
        //        max_ending_here = max_ending_here+AA[i];
        //    }
        //    else
        //    {
        //        isTaken.clear();
        //        max_ending_here = AA[i];
        //        isTaken.insert(i);
        //    }
        //    //max_ending_here = max_ending_here+AA[i] > AA[i] ? max_ending_here+AA[i] : AA[i];
        //    max_so_far = max_so_far < max_ending_here ? max_ending_here : max_so_far;
        //}
        //return max_so_far;
    }
};
