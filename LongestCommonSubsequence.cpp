/*
Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 
Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.

Hide Hint #1  
Try dynamic programming. DP[i][j] represents the longest common subsequence of text1[0 ... i] & text2[0 ... j].

Hide Hint #2  
DP[i][j] = DP[i - 1][j - 1] + 1 , if text1[i] == text2[j] DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) , otherwise

*/

class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.length();
        int size2 = text2.length();
        
        vector<vector<int>> DP(size2, vector<int>(size1));
        
        for(int i=0; i < size1; i++)
        {
            if(text1[i] == text2[0])
            {
                DP[0][i] = 1;
            }
            else
            {
                if(!i)
                    DP[0][i] = 0;
                else
                    DP[0][i] = DP[0][i-1];
            }
        }
        
        for(int i=0; i < size2; i++)
        {
            if(text1[0] == text2[i])
            {
                DP[i][0] = 1;
            }
            else
            {
                if(!i)
                    DP[i][0] = 0;
                else
                    DP[i][0] = DP[i-1][0];
            }
        }
        
        for(int i=1; i<size2; i++)
        {
            for(int j=1; j<size1; j++)
            {
                DP[i][j] = (text1[j] == text2[i]) ? (DP[i-1][j-1]+1) : (DP[i][j-1] > DP[i-1][j] ? DP[i][j-1] : DP[i-1][j]);
            }
        }
        return DP[size2-1][size1-1];
    }
};
