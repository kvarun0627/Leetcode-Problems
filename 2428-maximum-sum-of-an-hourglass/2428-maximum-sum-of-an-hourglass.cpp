class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m-2;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                ans=max(ans,grid[i][j-1]+grid[i][j]+grid[i][j+1]+grid[i+1][j]+grid[i+2][j-1]+grid[i+2][j]+grid[i+2][j+1]);
            }
        }
        return ans;
    }
};