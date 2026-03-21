class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>DP(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + grid[i-1][j-1];
            }
        }

        int ans = 0;
        for(int i=1;i<=m;i++)
        {
            auto it = upper_bound(DP[i].begin(),DP[i].end(),k)-DP[i].begin()-1;
            ans+=it;

        }
        return ans;
    }
};