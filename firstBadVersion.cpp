/*
First Bad Version

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 

*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int result;
    void checkBadVersion(int beg, int end)   //pass 1, n+1 here as versions are marked from 1
    {
        if(beg <= end)
        {
            int mid = beg + (end-beg)/2 ;
            if(isBadVersion(mid))
            {
                result = result > mid ? mid : result;
                checkBadVersion(beg, mid-1);
            }
            else
            {
                checkBadVersion(mid+1, end);
            }
        }
    }
    
    int firstBadVersion(int n) {
        result = n;
        checkBadVersion(1, n);
        return result;
    }
};
