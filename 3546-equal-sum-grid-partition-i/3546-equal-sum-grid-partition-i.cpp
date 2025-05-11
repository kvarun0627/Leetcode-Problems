class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>>pref(m+1,vector<long long>(n+1,0));
        long long sum=0;
        for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                    {
                        pref[i][j]=grid[i-1][j-1]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
                        sum+=grid[i-1][j-1];
                    }
            }
        for(int i=0;i<m-1;i++)
            {
                int col1=0;
                int col2=n-1;
                int row1=0;
                int row2=i;
                long long ans=pref[row2+1][col2+1]+pref[row1][col1]-pref[row2+1][col1]-pref[row1][col2+1];
                if(ans==sum-ans)
                {
                    return true;
                }
            }
        for(int i=0;i<n-1;i++)
            {
                int col1=0;
                int col2=i;
                int row1=0;
                int row2=m-1;
                long long ans=pref[row2+1][col2+1]+pref[row1][col1]-pref[row2+1][col1]-pref[row1][col2+1];
                if(ans==sum-ans)
                {
                    return true;
                }
            }
        return false;
    }
};