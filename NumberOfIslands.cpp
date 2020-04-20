/*
Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000

Output: 1

Example 2:
Input:
11000
11000
00100
00011

Output: 3

*/

class Solution {
public:
    int answer, rowSize, colSize;
    
    void init(vector<vector<bool>> &visited)
    {
        answer = 0;
        for(int i=0; i<rowSize; i++)
        {
            for(int j=0; j<colSize; j++)
            {
                visited[i][j] = false;
            }
        }
    }
    
    bool isValid(int i, int j)
    {
        if(i >= 0 && i < rowSize && j >= 0 && j < colSize)
            return true;
        return false;
    }
    
    void findIsland(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        int coordx[]={0, -1, 1, 0};    //left, top, bottom, right
        int coordy[]={-1, 0, 0, 1};    //left, top, bottom, right
        int tmpx, tmpy;
        
        for(int i=0; i<4; i++)
        {
            tmpx = x + coordx[i];    
            tmpy = y + coordy[i];
            
            if( isValid(tmpx, tmpy) && grid[tmpx][tmpy]-'0' && !visited[tmpx][tmpy])
            {
                visited[tmpx][tmpy] = true;
                findIsland(tmpx, tmpy, visited, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        rowSize = grid.size();
        if(rowSize)
            colSize = grid[0].size();
        else
            return 0;

        vector<vector<bool>> visited(rowSize, vector<bool>(colSize));
        
        init(visited);
        
        for(int i=0; i<rowSize; i++)
        {
            for(int j=0; j<colSize; j++)
            {
                if(grid[i][j]-'0' && !visited[i][j])
                {
                    answer++;
                    visited[i][j] = true;
                    findIsland(i, j, visited, grid);
                }
            }
        }
        return answer;
    }
};
