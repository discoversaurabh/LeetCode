/*
Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.

*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        if(!N)
        {
            if(!amount) 
                return 1;
            else
                return 0;
        }
        vector<vector<int>> DP(N,vector<int>(amount+1,INT_MAX));
        //DP[0][0] = 0;
        
        for(int i=0; i < N; i++)
            DP[i][0] = 0;
        
        for(int n=0; n<N; n++)
        {
            for(int s=1; s < amount+1; s++)
            {
                //if(n > 0)
                //    DP[n][s] = DP[n-1][s];
                
                if(s >= coins[n] && DP[n][s-coins[n]] != INT_MAX)
                    DP[n][s] = 1+DP[n][s-coins[n]];//max(DP[n-1][s], 1+DP[n][s-coins[n]]);
                if(n > 0)
                    DP[n][s] = DP[n-1][s] < DP[n][s] ? DP[n-1][s] : DP[n][s];
            }
        }
        return DP[N-1][amount] == INT_MAX ? -1 : DP[N-1][amount];
    }
};
