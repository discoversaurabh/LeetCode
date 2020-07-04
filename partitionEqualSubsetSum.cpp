class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size(), sum=0;
        
        for(int n:nums)
        {
            sum += n;
        }
        if(sum % 2) return false;
        sum = sum/2;
        
        vector<vector<bool>> DP(N+1, vector<bool>(sum+1,false));
        DP[0][0] = true;    //null set
        for(int row=1; row < N+1; row++)
        {
            for(int col=0; col < sum+1; col++)
            {
                if(!col)
                {
                    DP[row][col] = true;
                    continue;
                }
                if(col-nums[row-1] >= 0)
                    DP[row][col] = (DP[row-1][col] || DP[row-1][col-nums[row-1]]);
                else
                    DP[row][col] = DP[row-1][col];
            }
        }
        return DP[N][sum];
    }
};
