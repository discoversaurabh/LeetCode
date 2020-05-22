/*
Permutation in String

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
 
Constraints:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

Hide Hint #1  
Obviously, brute force will result in TLE. Think of something else.

Hide Hint #2  
How will you check whether one string is a permutation of another string?

Hide Hint #3  
One way is to sort the string and then compare. But, Is there a better way?

Hide Hint #4  
If one string is a permutation of another string then they must one common metric. What is that?

Hide Hint #5  
Both strings must have same character frequencies, if one is permutation of another. Which data structure should be used to store frequencies?
   
Hide Hint #6  
What about hash table? An array of size 26?

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> pat(26), window(26);
        int pL=s1.length(), iL=s2.length(); //pattern length and input length
        for(int i=0; i<pL; i++)
            pat[s1[i]-'a']++;
        for(int i=0; i<iL; i++)
        {
            if(i < pL)
                window[s2[i]-'a']++;
            else
            {
                if(window == pat)
                    return true;
                window[s2[i]-'a']++;
                window[s2[i-pL]-'a']--;
            }
        }
        //check last index based substring as that will skip
        if(window == pat)
            return true;
        return false;
    }
};
