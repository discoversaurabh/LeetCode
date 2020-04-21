#if 1
/*
Leftmost Column with at Least a One

(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

Example 1:
Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:
Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:
Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1

Constraints:
1 <= mat.length, mat[i].length <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.

*/
#include"AllHeader.h"

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

vector<vector<int>> arr = { {0,0,0,1} ,{0,0,1,1},{0,1,1,1}};
//vector<vector<int>> arr = { {0,0} ,{1,1} };

class BinaryMatrix {
public:
	int get(int x, int y) {
		return arr[x][y];
	}
	vector<int> dimensions()
	{
		return { (int)arr.size(), (int)arr[0].size() };
	}
};

class Solution {
public:
	int answer, ansL;
	// vector<vector<int>> arr;

	int binSearch(int row, int beg, int end, BinaryMatrix &bM, vector<vector<int>> &arr)
	{
		int tmp;
		if (beg == end)
		{
			if (arr[row][beg] != 0)
			{
				ansL = ansL < beg ? ansL : beg;
				return ansL;
			}
			else
			{
				arr[row][beg] = bM.get(row, beg);
				if (arr[row][beg] == 1)
					return beg;
				else
					return INT_MAX;
			}
		}

		if (beg > end)
			return INT_MAX;

		int mid = beg + (end - beg) / 2;
		arr[row][mid] = bM.get(row, mid);

		if (arr[row][mid] == 1)
		{
			ansL = ansL < mid ? ansL : mid;
			tmp = binSearch(row, beg, mid - 1, bM, arr);
			ansL = ansL < tmp ? ansL : tmp;
			return ansL;
		}
		else
		{
			tmp = binSearch(row, mid + 1, end, bM, arr);
			ansL = ansL < tmp ? ansL : tmp;
			return ansL;
		}
	}

	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
		answer = ansL = INT_MAX;
		int m, n, tmp;
		vector<int> size = binaryMatrix.dimensions();
		m = size[0];
		n = size[1];
		vector<vector<int>> arr(m, vector<int>(n)); // for saving data already fetched to reduce repetetive calls

		/*for(int i=0; i<m ;++i)
		{
			for(int j=0; j<n; j++)
			{
				arr[i][j] = -1;
			}
		}*/
		for (int i = 0; i < m; i++)
		{
			tmp = binSearch(i, 0, n - 1, binaryMatrix, arr);
			answer = tmp < answer ? tmp : answer;
		}
		if (answer == INT_MAX)
			return -1;
		return answer;
	}
};

int main()
{
	Solution s;
	BinaryMatrix bm;
	cout << "Leftmost Column with at least a 1 : "<< s.leftMostColumnWithOne(bm) << endl;
	return 0;
}
#endif