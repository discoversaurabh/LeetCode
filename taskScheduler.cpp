/*
You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

Constraints:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

class Solution {
public:
    struct comp{
        bool operator()(pair<char,int> &p1, pair<char,int> &p2)
        {
            return p1.second < p2.second;
        }
    };
    
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        if(!size) return 0;
        unordered_map<char, int> freq;
        queue<pair<char,int>> que;
        int answer = 0;
        for(char c:tasks)
            freq[c]++;
        priority_queue<pair<char,int>, vector<pair<char,int>>, comp>maxHeap;
        
        for(pair<char,int> p:freq)
        {
            maxHeap.push(p);
        }
        while(!maxHeap.empty())
        {
            int d = n+1;
            while(d > 0 && !maxHeap.empty())
            {
                auto tp = maxHeap.top();
                maxHeap.pop();
                tp.second--;
                answer++;
                
                if(tp.second)
                    que.push(tp);
                
                d--;
            }
            
            while(!que.empty())
            {
                auto ft = que.front();
                que.pop();
                maxHeap.push(ft);
            }
                        
            if(d > 0 && !maxHeap.empty())
                answer += d;

        }
        return answer;
    }
};
