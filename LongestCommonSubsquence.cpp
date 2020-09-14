class Solution {
public:
    int solveRec(string& A, string& B, vector<vector<int>> &DP, int m, int n)
    {
        if(m < 0 || n < 0)
            return 0;

        if(DP[m][n] != -1)
            return DP[m][n];

        if(A[m] == B[n])
        {
            DP[m][n] = 1 + solveRec(A, B, DP, m-1, n-1);
        }
        else
        {
            DP[m][n] = max(solveRec(A, B, DP, m-1, n), solveRec(A, B, DP, m, n-1));
            
        }
        return DP[m][n];
    }
    
    int longestCommonSubsequence(string A, string B) {
        int N1 = A.size();
        int N2 = B.size();
        if(!N1 || !N2){
            return 0;
        }

        vector<vector<int>>DP(N1, vector<int>(N2, -1));
        return solveRec(A, B, DP, N1-1, N2-1);
    }
};
