#include<unordered_map>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        map.clear();
        int rnlen = ransomNote.length();
        int mlen = magazine.length();
        for(int i=0; i<mlen; ++i)
        {
            ++map[magazine[i]];
        }
        for(int i=0; i<rnlen; ++i)
        {
            if(map.find(ransomNote[i]) != map.end())
            {
                if(!map[ransomNote[i]]--) 
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};
