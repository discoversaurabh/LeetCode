/*
Minimum Path Sum (using DP)
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int sizeRow, sizeCol, answer;
    
    int getMin(int x, int y)
    {
        if(x < y)
        {
            return x;
        }
        else
        {
            return y;
        }
    }
   
    int findPathDP(int m, int n, vector<vector<int>>&grid)
    {
        // fill first row
        for(int i=1; i < n; i++)
            grid[0][i] = grid[0][i] + grid[0][i-1];

        // fill first column
        for(int i=1; i < m; i++)
            grid[i][0] = grid[i][0] + grid[i-1][0];

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
               grid[i][j] = getMin(grid[i-1][j], grid[i][j-1]) + grid[i][j]; 
            }
        }
        return grid[m-1][n-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int sizeRow = grid.size();
        int sizeCol;
        if(sizeRow)
            sizeCol = grid[0].size();
       // answer = INT_MAX;
        
        return findPathDP(sizeRow, sizeCol, grid);
    }
};
