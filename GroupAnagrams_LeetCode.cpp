#include<unordered_map>
#include<iostream>
#include<vector>
#include<algorithm>
#include<ostream>
#include<string>
#include<sstream>
#include<cassert>
#include<algorithm>
using namespace std;

typedef struct STORE
{
	string str;
	int id;
}store;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<store>> result;
		vector<vector<string>> finalResult;
		int size = strs.size();
		vector<store> mapid(size);
		
		result.clear();
		finalResult.clear();

		for (int i = 0; i < size; i++)
		{
			mapid[i].id = i;
			mapid[i].str = strs[i];
		}

		for (int i = 0; i < size; i++)
		{
			sort(mapid[i].str.begin(), mapid[i].str.end());
		}

		sort(mapid.begin(), mapid.end(), [](store s1, store s2) { return s1.str < s2.str; });
			   
		//sort(strs.begin(), strs.end());
		int counter = 0, lcounter = 0;
		result.push_back(vector<store>());
		result[counter].push_back(mapid[0]);
		for (int i = 1; i < size; i++)
		{
			
			if (mapid[i].str.compare(mapid[i-1].str) == 0)    //same
				result[counter].push_back(mapid[i]);
			else
			{
				counter++;
				//if (i != size)
				result.push_back(vector<store>());
				result[counter].push_back(mapid[i]);
			}
		}

		for (int i = 0; i < result.size(); i++)
		{
			finalResult.push_back(vector<string>());
			//finalResult[i].push_back(vector<string>());
			for(int j=0; j<result[i].size(); j++)
			{
				//finalResult[i].push_back(vector<string>());
				finalResult[i].push_back(strs[result[i][j].id]);
				//finalResult[i][j] = strs[result[i][j].id];
			}
		}
		//if (strs[i].compare(strs[i - 1]) == 0)    //same
		//	result[counter].push_back(strs[i]);
		//else
		//{
		//	counter++;
		//	//if (i != size)
		//	result.push_back(vector<string>());
		//	result[counter].push_back(strs[i]);
		//}

		return finalResult;
	}
};

int main()
{
	vector<string> vec = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> result;
	Solution s;
	result.clear();
	result = s.groupAnagrams(vec);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}