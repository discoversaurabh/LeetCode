#if 1
#include"AllHeader.h"
/*
Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
			 To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
			 To take course 1 you should have finished course 0, and to take course 0 you should
			 also have finished course 1. So it is impossible.


Constraints:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

Hide Hint #1
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.

Hide Hint #2
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.

Hide Hint #3
Topological sort could also be done via BFS.

*/

/*
SAURABH APPROACH : SIMPLE FIND CYCLE LOGIC...program involves some c++ tricks which make it little complex to implement
*/

class Solution {
public:

	bool util(int index, int n, vector<vector<int>>& pre, vector<bool> &visited)
	{
		for (auto p = pre[index].begin(); p != pre[index].end(); ++p)
		{
			if (visited[*p])
				return false;
			else
			{
				visited[*p] = true;
				if (!util(*p, n, pre, visited))
					return false;
				visited[*p] = false;
			}
		}
		return true;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (numCourses <= 1) return true;
		vector<bool> visited(numCourses, false);
		vector<vector<int>> pre(numCourses);
		for (auto p : prerequisites)
		{
			pre[p[0]].push_back(p[1]);
		}

		for (int i = 0; i < pre.size(); i++)
		{
			for(auto p=pre[i].begin(); p != pre[i].end(); ++p)
			{
				if (!visited[i])
				{
					visited[i] = true;
					if (!util(*p, numCourses, pre, visited))
						return false;
					visited[i] = false;
				}
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> num = { {1, 0},{0, 1} };
	cout<<"ans:"<<s.canFinish(2, num)<<endl;
	return 0;
}

#endif