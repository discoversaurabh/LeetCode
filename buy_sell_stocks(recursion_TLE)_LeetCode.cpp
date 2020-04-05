#include<unordered_map>
#include<iostream>
#include<vector>
#include<algorithm>
#include<ostream>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

class Solution {
public:

	int calcMaxProfit(vector<int>& prices, int beg, int end)
	{
		int lp = 0, maxp = 0, lmax = 0;
		for (int i = beg; i < end - 1; ++i)
		{
			lp = 0;
			for (int j = i + 1; j < end; j++)
			{
				if (prices[i] < prices[j])
				{
					lp = prices[j] - prices[i] + calcMaxProfit(prices, j + 1, end);
				}
				lmax = (lmax > lp) ? lmax : lp;
			}
			maxp = (maxp > lmax) ? maxp : lmax;
		}
		
		return maxp;
	}

	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		return calcMaxProfit(prices, 0, size);
	}
};

int main()
{
	vector<int> vec = {7,1,5,3,6,4};
	Solution s;
	cout<<"Output is : "<<s.maxProfit(vec)<<endl;
	return 0;
}