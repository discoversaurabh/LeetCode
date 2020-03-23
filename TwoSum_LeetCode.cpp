#include<unordered_map>
#include<iostream>
#include<vector>
#include<algorithm>
#include<ostream>
#include<string>
#include<sstream>

using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		int size = nums.size();

		//store numbers along with their positions
		for (int i = 0; i < size; i++)
		{
			map[nums[i]] = i;
		}

		//now traverse each num and check corresponding pair's location
		for (int i = 0; i < size; i++)
		{
			if (map.find(target - nums[i]) != map.end())
			{
				return { i, map[target - nums[i]] };
			}
		}
		return { NULL };
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(string input) {
	return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	//input:
	//[2,7,11,15]
	//9
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		
		int target = stringToInteger(line);

		vector<int> ret = Solution().twoSum(nums, target);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}