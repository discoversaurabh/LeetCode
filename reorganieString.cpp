/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/

class Solution {
public:
    
    struct comp
    {
        bool operator()(pair<char, int> &p1, pair<char,int> &p2)
        {
            return p1.second < p2.second;
        }
    };
    
    string reorganizeString(string S) {
        int size = S.size();
        unordered_map<char, int> freq;
        string answer;
        priority_queue<pair<char, int>, vector<pair<char,int>>, comp> maxHeap;
        
        for(char s:S)
        {
            freq[s]++;
            if(freq[s] > size/2+1)
                return "";
        }
        
        for(pair<char,int> p:freq)
        {
            maxHeap.push(p);
        }
        
        pair<char, int> prev = maxHeap.top();
        maxHeap.pop();
        answer += prev.first;
        prev.second--;
        
        while(!maxHeap.empty())
        {
            pair<char,int> cur = maxHeap.top();
            maxHeap.pop();
            answer += cur.first;
            cur.second--;
            if(prev.second > 0)
                maxHeap.push(prev);
            prev = cur;
        }
        //cout<<"ANS:"<<answer<<endl;
        return (answer.size() == S.size())?answer:"";
        
    }
};
