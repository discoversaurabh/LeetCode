/*

Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int M=matrix.size();
        if(!M) return {};
        int N = matrix[0].size();
        
        vector<int> result;
        int rowL=0, rowH=M-1, colL=0, colH=N-1;
        
        while(rowL <= rowH && colL <= colH)
        {
            for(int i=colL; i<=colH; i++)
                result.push_back(matrix[rowL][i]);
            
            for(int i=rowL+1; i<=rowH; i++)
                result.push_back(matrix[i][colH]);
            
            if(colL != colH && rowL != rowH)    //when only one row or one col is left, skip them
            {
                for(int i=colH-1; i>=colL; i--)
                    result.push_back(matrix[rowH][i]);
            
                for(int i=rowH-1; i>rowL; i--)
                    result.push_back(matrix[i][colL]);
            }
            
            rowL++;
            rowH--;
            colL++;
            colH--;
        }
        return result;
        
    }
};
