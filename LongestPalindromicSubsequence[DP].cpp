/*
Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
 

Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> DP(N, vector<int>(N,0));
        for(int i=0; i<N; i++)
        {
            DP[i][i] = 1;   //letter with self is palindrome
        }
        
        for(int start = N-1; start >= 0; start--)
        {
            for(int end=start+1; end < N; end++)
            {
                if(s[start] == s[end])
                    DP[start][end] = 2 + DP[start+1][end-1];
                else
                    DP[start][end] = max(DP[start+1][end], DP[start][end-1]);
            }
        }
        return DP[0][N-1];
    }
};
