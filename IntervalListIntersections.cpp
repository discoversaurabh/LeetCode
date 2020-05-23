/*
Interval List Intersections

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Example 1:
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.

Note:
0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/

class Solution {
public:
    
    bool overlap(int x1, int y1, int x2, int y2)
    {
        if(y1 < x2 || y2 < x1)
            return false;
        return true;
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        int i=0, j=0;
        int st=0, end=0;
        int size1=A.size(), size2=B.size();
        while(i<size1 && j<size2)
        {
            if(overlap(A[i][0], A[i][1], B[j][0], B[j][1]))
            {
                st = max(A[i][0],B[j][0]);
                end = min(A[i][1], B[j][1]);
                result.push_back({st,end});
            }
            if(A[i][1] < B[j][1])
                i++;
            else
                j++;
        }
        return result;
    }
};
