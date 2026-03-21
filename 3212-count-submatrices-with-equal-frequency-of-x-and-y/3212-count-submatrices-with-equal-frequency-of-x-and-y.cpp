class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>DP(m+1,vector<int>(n+1,0)),DP1(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                DP[i][j] = ((grid[i-1][j-1]=='X')?1:0) + DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1];

                DP1[i][j] = ((grid[i-1][j-1]=='Y')?1:0) + DP1[i-1][j] + DP1[i][j-1] - DP1[i-1][j-1];
            }
        }

        int ans = 0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(DP[i][j] == DP1[i][j] && DP[i][j]>0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};