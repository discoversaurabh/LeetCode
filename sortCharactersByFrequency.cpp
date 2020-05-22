/*
Sort Characters By Frequency

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> fM;
        string result="";
        for(int i=0; i<s.length(); i++)
            fM[s[i]]++;

        sort(s.begin(), s.end(), [&fM](char a, char b){
            //return fM[a] >= fM[b];// || (fM[a] == fM[b] && a<b));
            return ((fM[a] > fM[b]) || (fM[a] == fM[b] && a<b));
        });
        
        return s;
    }
};
