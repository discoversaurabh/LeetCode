/*
Remove K Digits

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

#include"AllHeader.h"
class Solution {
public:
	string removeKdigits(string num, int k) {
		int len = num.length();
		//string result="";
		int removeCount = 0;
		int i = 0;

		//if(k == len)
		//    return "0";

		while (i < num.size() - 1 && removeCount < k)
		{
			//incremental order, do not worry
			while (num[i] - '0' > num[i + 1] - '0' && i < num.size() - 1 && removeCount < k)
			{
				removeCount++;
				num.erase(i,1);
				if (--i < 0)
					i = 0;//go one stpe back
			}
			i++;
		}
		cout << "num:" << num;
		int resLen;
		if (removeCount != k)
		{
			resLen = num.length();
			resLen--;
			while (removeCount < k)
			{
				num.erase(resLen--,1);
				removeCount++;
			}
		}

		//erase leading zeros
		i = 0;
		while (i < num.length())
		{
			if (num[i] == '0')
				num.erase(i,1);
			else
				break;
		}

		if (num == "")
			return "0";
		return num;
	}
};

int main()
{
	//string str = "1432219";
	//string str2 = "10200";
	string str3 = "1234567890";
	Solution s;
	//cout<<"Result String: "<<s.removeKdigits(str, 3)<<endl;
	//cout << "Result String: " << s.removeKdigits(str2, 1) << endl;
	cout << "Result String: " << s.removeKdigits(str3, 9) << endl;
	return 0;
}
