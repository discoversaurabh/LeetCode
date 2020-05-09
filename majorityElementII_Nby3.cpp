/*
Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:
Input: [3,2,3]
Output: [3]

Example 2:
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int result1, result2, count1=0, count2 = 0, size = nums.size();
        if(size == 0)
            return {};
        if(size == 1)
            return {nums[0]};
        //for(int i=0; i<size; i++)
        //{
        //    cout<<nums[i]<<" ";
        //}
        //cout<<endl;
        for(int i=0; i<size; i++)
        {
           // cout<<"i="<<i<<" ";
            if(!count1 && (!count2 || (count2 && result2 != nums[i])))
            {
                //cout<<i<<"-u1-"<<nums[i]<<" ";
                result1 = nums[i];
                count1 = 1;
            }
            else if(!count2 && count1 && nums[i] != result1)
            {
                //cout<<i<<"-u2e-"<<nums[i]<<" ";
                result2 = nums[i];
                count2 = 1;
            }
            else if(result1 == nums[i])
            {
                //cout<<i<<"-p1 ";
                count1++;
            }
            else if(result2 == nums[i])
            {
                //cout<<i<<"-p2 ";
                count2++;
            }
            else
            {
                //cout<<i<<"-ln ";
                count1--;
                count2--;
            }
        }
        //cout<<result1<<" "<<result2<<endl;
        // SAURAH NOTE:
        // now we need to check final count again because the count we have is much less
        // and does not depict the actual count since we were decrementing it whenever
        // a different element encountered
        // and return -1 or so if at east no such single element exist
        // but since problem does not talk about error case (-1 case)
        // so i will exclude this
        
        //get actual count now
        count1 = count2 = 0;
        for(int i=0; i<size; i++)
        {
            if(result1 == nums[i])
                count1++;
            else if(result2 == nums[i])
                count2++;
        }
        if(count1 > size/3)
        {
            if(count2 > size/3)
            {
                return {result1, result2};
            }
            else
                return {result1};
        }
        else
        {
            if(count2 > size/3)
            {
                return {result2};
            }
            else
                return {};
        }
    }
};
