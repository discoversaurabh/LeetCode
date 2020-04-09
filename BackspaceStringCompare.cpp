/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

class Solution {
public:
    
    bool backspaceCompare(string S, string T) {
        int size = S.length(), j = 0;
        for(int i = 0; i < size; ++i)
        {
            if(S[i] != '#')
            {
                S[j] = S[i];
                j++;
            }
            else
            {
                j--;
                if(j<0) j = 0;
            }
        }
        //S[j] = NULL;  //cannot terminate string with NULL
        //S[j] = 0;  //cannot terminate string with 0
        S = S.substr(0,j);
        j=0,size = T.length();
        for(int i = 0; i < size; ++i)
        {
            if(T[i] != '#')
            {
                T[j] = T[i];
                j++;
            }
            else
            {
                j--;
                if(j<0) j = 0;
            }
        }
        //T[j] = NULL;  //cannot terminate string with NULL
        //T[j] = 0;  //cannot terminate string with 0
        T = T.substr(0,j);
        
        if(S == T)
            return true;
        return false;
    }
};
