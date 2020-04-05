#if 1
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

	int stockBuySell(vector<int>& price, int n)
	{
		if (n == 1)
			return 0;

		int i = 0, maxp = 0;
		while (i < n - 1) {
			while ((i < n - 1) && (price[i + 1] <= price[i]))
				i++;

			if (i == n - 1)
				break;

			int buy = i++;

			while ((i < n) && (price[i] >= price[i - 1]))
				i++;

			int sell = i - 1;

			maxp += price[sell] - price[buy];
		}
		return maxp;
	}

	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		return stockBuySell(prices, size);
	}
};

int main()
{
	vector<int> vec = { 4,3,2,7,1,8 };
	Solution s;
	cout << "Output is : " << s.maxProfit(vec) << endl;
	return 0;
}
#endif