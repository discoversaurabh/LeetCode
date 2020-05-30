#include"AllHeader.h"
/*
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)



Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)


Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

*/

class Solution {
public:

	struct comp
	{
		bool operator()(pair<long, pair<int, int>> &a, pair<long, pair<int, int>> &b)
		{
			return a.first < b.first;
		}
	};

	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		//maintain a heap of k points
		vector<vector<int>>result;
		priority_queue<pair<long, pair<int, int>>, vector<pair<long, pair<int, int>>>, comp>maxHeap;
		long count = 0, dist = 0;
		for (int i = 0; i < points.size(); i++)
		{
			int p1, p2;
			p1 = (points[i][0] < 0) ? ((-1)*points[i][0]) : points[i][0];
			p2 = (points[i][1] < 0) ? ((-1)*points[i][1]) : points[i][1];
			dist = p1 * p1 + p2 * p2;

			if (count < K)
			{
				maxHeap.push(make_pair((long)dist, make_pair(points[i][0], points[i][1])));
				count++;
				continue;
			}

			auto top = maxHeap.top();
			if (top.first > dist)
			{
				maxHeap.pop();
				maxHeap.push(make_pair((long)dist, make_pair(points[i][0], points[i][1])));
			}
		}
		count = 0;
		while (count < K && maxHeap.empty() == false)
		{
			auto top = maxHeap.top();
			maxHeap.pop();
			result.push_back({ top.second.first, top.second.second });
			count++;
		}
		return result;
	}
};

int main()
{
	vector<vector<int>> vec = { {-95, 76}, {17, 7}, {-55, -58}, {53, 20}, {-69, -8}, {-57, 87}, {-2, -42}, {-10, -87}, {-36, -57}, {97, -39}, {97, 49} };
	Solution s;
	s.kClosest(vec, 5);
	return 0;
}