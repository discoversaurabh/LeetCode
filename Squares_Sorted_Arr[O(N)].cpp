/*
Squares of a Sorted Array [O(N) Solution]
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

Example 1:
Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Example 2:
Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.

*/
#include"AllHeader.h"

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		int size = A.size(), tmp, start = -1, ind = 0;
		vector<int> result(A.begin(), A.end());
		tmp = A[0];

		for (int i = 0; i < size; i++)
		{
			result[i] = result[i] * result[i];
		}
		for (int i = 1; i < size; i++)
		{
			if (tmp*tmp < A[i] * A[i])
			{
				start = i - 1;
				break;
			}
			else if (i == size-1)
			{
				start = i;
				break;
			}
			tmp = A[i];
		}
		if (start != -1)
		{
			int i = start - 1, j = start;
			while (i >= 0 && j < size)
			{
				if (A[i] * A[i] < A[j] * A[j])
				{
					result[ind++] = A[i] * A[i];
					i--;
				}
				else
				{
					result[ind++] = A[j] * A[j];
					j++;
				}
			}
			while (i >= 0)
			{
				result[ind++] = A[i] * A[i];
				i--;
			}
			while (j < size)
			{
				result[ind++] = A[j] * A[j];
				j++;
			}
		}
		return result;

	}
};

int main()
{
	Solution s;
	//vector<int> vec = { -4,-1,0,3,10 };
	vector<int> vec = { -3,-3,-2,1 };
	s.sortedSquares(vec);
	return 0;
}
