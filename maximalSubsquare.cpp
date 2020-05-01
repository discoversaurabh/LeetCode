/*
Maximal Square

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:
Input:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

*/
#include"AllHeader.h"
class Solution {
public:

	int getMin(int a, int b, int c)
	{
		return (a < b ? (a < c ? a : c) : (b < c ? b : c));
	}

	int maximalSquare(vector<vector<char>>& matrix) {
		int sizeR = matrix.size();
		if (!sizeR) return 0;
		int sizeC = matrix[0].size();

		vector<vector<int>> arr(sizeR + 1, vector<int>(sizeC + 1, 0));
		int maxSquareSize = INT_MIN, I, J;

		for (int i = 1; i < sizeR + 1; i++)
		{
			for (int j = 1; j < sizeC + 1; j++)
			{
				I = i - 1;    //since original matrix is 1 unit size less
				J = j - 1;    //since original matrix is 1 unit size less
				if (matrix[I][J] == '1')
					arr[i][j] = getMin(arr[i][j - 1], arr[i - 1][j - 1], arr[i - 1][j]) + 1;
				else
					arr[i][j] = 0;

				maxSquareSize = maxSquareSize < arr[i][j] ? arr[i][j] : maxSquareSize;
			}
		}
		return maxSquareSize * maxSquareSize;
	}
};

int main()
{
	vector<vector<char>> mat = {
								{'1', '0', '1', '0', '0'},
								{'1', '0', '1', '1', '1'},
								{'1', '1', '1', '1', '1'},
								{'1', '0', '0', '1', '0'} 
								};
	Solution s;
	cout<<"Max Subsquare of 1s elements count: "<<s.maximalSquare(mat)<<endl;
	return 0;
}