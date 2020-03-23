#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<string>
#include<cassert>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = s.length(), left = 0, right = 0, maxLen = 0;
		unordered_map<char, int> map(len);


		for (; right < len; right++)
		{
			map[s.at(right)]++;
			while (map[s.at(right)] > 1)
			{
				map[s.at(left)]--;
				left++;
			}
			maxLen = (maxLen > (right - left + 1)) ? maxLen : (right - left + 1);
		}
		return maxLen;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

//input :
//"abcabcbb"
//output:3 

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);

		int ret = Solution().lengthOfLongestSubstring(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}