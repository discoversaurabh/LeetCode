/*
Edit Distance

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/

/*
APPROACH (SAURABH): Refer Tushar Roy explanation on you tube 
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.length(), size2 = word2.length();
        vector<vector<int>> dpArr(size1+1, vector<int>(size2+1, 0));
        for(int i=0; i<size1+1; i++)
        {
            for(int j=0; j<size2+1; j++)
            {
                if(!i)
                    dpArr[i][j] = j;
                else if(!j)
                    dpArr[i][j] = i;
                else if(word1[i-1] == word2[j-1])
                    dpArr[i][j] = dpArr[i-1][j-1];
                else
                {
                    dpArr[i][j] = 1 + min(dpArr[i-1][j-1], min(dpArr[i-1][j], dpArr[i][j-1]));
                }
            }
        }
        return dpArr[size1][size2];
    }
};
