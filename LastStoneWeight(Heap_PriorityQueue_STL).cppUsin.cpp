class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // pair<int, int> pr;
        priority_queue<int> pq;
        int tmp = 0;
        // pq.reset();
        for(int i=0; i< stones.size(); i++)
        {
            pq.push(stones[i]);
        }
        
        while(pq.size())
        {
            tmp = pq.top();
            pq.pop();
            
            if(pq.size() >= 1)
            {
                tmp -= pq.top();
                pq.pop();
            }
            else 
                return tmp;
            
            pq.push(tmp);
        }
        return 0;   //Practically control should never reach here.
    }
};
