/*
Top K Frequent Elements

Given a non - empty array of integers, return the k most frequent elements.

	Example 1:
	Input: nums = [1, 1, 1, 2, 2, 3], k = 2
	Output : [1, 2]

	Example 2 :
	Input : nums = [1], k = 1
	Output : [1]
	
	Note :
	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
	Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
	It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
	You can return the answer in any order.
*/
#include"AllHeader.h"
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> freq;
		vector<int> result;
		int size = nums.size();

		for (int i = 0; i < size; i++)
			freq[nums[i]]++;

		//dont create this instead create a priority queue and do this by selecting k elemenets
			//vector<pair<int, int>> fetchK;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
		unordered_map<int, int>::iterator it;
		it = freq.begin();
		for (int i = 0; i < k; i++)
		{
			pq.push(make_pair(it->second, it->first));
			//pq.pop();
			++it;
		}
		//auto en = freq.end();
		//en--;
		int tmp;
		while (it != freq.end())
		{
			tmp = pq.top().first;
			//pop one and insert 1 in heap
			if (it->second > tmp)
			{
				pq.pop();
				// only insert if incoming element is more than the already min we have
				// at the top of the min heap
				pq.push(make_pair(it->second, it->first));
			}
			++it;
		}

		// our heap is ready by now
		int i = 0;
		while (i < k)
		{
			result.push_back(pq.top().second);
			pq.pop();
			++i;
		}
		return result;
	}
};

int main()
{
	vector<int> vec = {1,1,1,2,2,3};
	Solution s;
	s.topKFrequent(vec, 2);
	return 0;
}