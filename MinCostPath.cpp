/*
Minimum Path Sum
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
    int sizeRow, sizeCol;
    int answer;
    bool isValid(int i, int j)
    {
        if(i >= 0 && i < sizeRow && j >= 0 && j<sizeCol)
            return true;
        return false;
    }
    
    void findMinPath(int i, int j, int pathSum, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        int coordx[]={0, 1, 0, -1}; //right, down, left, up =>row
        int coordy[]={1, 0, -1, 0}; //right, down, left, up =>column
        int tmpx, tmpy;
        
        if(i == sizeRow-1 && j == sizeCol-1)
        {
            answer = answer < pathSum ? answer : pathSum;
            return;
        }
        
        for(int a=0; a<4; a++)
        {
            tmpx = i+coordx[a];
            tmpy = j+coordy[a];
            if(isValid(tmpx, tmpy) && !visited[tmpx][tmpy])
            {
                visited[tmpx][tmpy] = true;
                findMinPath(tmpx, tmpy, pathSum+grid[tmpx][tmpy], grid, visited);
                visited[tmpx][tmpy] = false;
            }
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        sizeRow=grid.size();
        if(sizeRow)
            sizeCol = grid[0].size();
        answer = INT_MAX;
        vector<vector<bool>> visited(sizeRow, vector<bool>(sizeCol));
        
        for(int i=0; i<sizeRow; i++)
        {
            //visited.push_back(new vector<bool>());
            for(int j=0; j<grid[i].size(); j++)
            {
                //visited[i].push_back(false);
                visited[i][j] = false;
            }
        }
        visited[0][0] = true;
        findMinPath(0,0,grid[0][0],grid, visited);
        return answer;
    }
};
