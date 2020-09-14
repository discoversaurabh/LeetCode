/*

Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        if(N <= 2)
            return 0;
        
        vector<int> lMax(N, 0);
        vector<int> rMax(N, 0);
        
        lMax[0] = height[0];
        for(int i=1; i<N; i++)
            lMax[i] = max(lMax[i-1], height[i]);
        
        rMax[N-1] = height[N-1];
        for(int i=N-2; i>=0; i--)
            rMax[i] = max(rMax[i+1], height[i]);
        
        int tmp,water = 0;
        for(int i=0; i<N; i++)
        {
            tmp = min(lMax[i], rMax[i]) - height[i];
            if(tmp > 0)
                water += tmp; 
        }
        return water;
    }
};
