class Solution {
public:
    
    void recPermute(vector<vector<int>>& result, vector<int>& nums, vector<bool>& visited, vector<int> &elem, int num, int& size)
    {
        if(num == size)
        {
            result.push_back(elem);
            return;
        }
    
        for(int i=0; i<size; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                elem.push_back(nums[i]);
                recPermute(result, nums, visited, elem, num+1, size);
                elem.pop_back();
                visited[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        vector<int>elem;
        vector<bool> visited(size);
        for(int i=0; i<size; i++)
        {
            elem.clear();
            visited.clear();
            visited[i] = true;
            elem.push_back(nums[i]);
            recPermute(result, nums, visited, elem, 1, size);
            visited[i] = false;
            //result.push_back(elem);
        }
        return result;
    }
};
