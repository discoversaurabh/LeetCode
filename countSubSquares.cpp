/*
Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

Constraints:
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

Hide Hint #1  
Create an additive table that counts the sum of elements of submatrix with the superior corner at (0,0).

Hide Hint #2  
Loop over all subsquares in O(n^3) and check if the sum make the whole array to be ones, if it checks then add 1 to the answer.

*/

class Solution {
public:
    
    int getMin(int a,int b, int c)
    {
        if(a<b)
            return ((b<c)?a:((a<c)?a:c));
        else
            return ((a<c)?b:((b<c)?b:c));
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int sum = 0, rSize = matrix.size(), cSize=rSize?matrix[0].size():0;
        if(!rSize) return 0;
        vector<vector<int>> result(rSize, vector<int>(cSize));
        
        for(int i=0; i< rSize; i++)
        {
            for(int j=0; j<cSize; j++)
            {
                if(!i || !j)
                {
                    if(matrix[i][j])
                    {
                        result[i][j] = matrix[i][j];
                        sum += 1;
                        cout<<"i= "<<i<<", j="<<j<<", sum="<<sum<<endl;
                    }
                    continue;   //dont do anything for 0th row and 0th column items
                }
                else
                {
                    if(matrix[i][j])
                    {
                        result[i][j] = getMin(result[i-1][j], result[i][j-1], result[i-1][j-1]) + 1;
                        sum += result[i][j];
                        cout<<"i= "<<i<<", j="<<j<<", sum="<<sum<<endl;
                    }
                }
            }
        }
        return sum;
    }
};
