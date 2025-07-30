class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{-1,0},{0,-1},{1,0}};
    int mod=1e9+7;
    int solve(int x,int y,vector<vector<int>>& grid,vector<vector<int>>&DP,int m,int n)
    {
        if(DP[x][y]!=-1)
        {
            return DP[x][y];
        }

        int ans=1;
        for(auto d:dir)
        {
            int nx=x+d.first;
            int ny=y+d.second;

            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]>grid[x][y])
            {
                ans=(ans+solve(nx,ny,grid,DP,m,n))%mod;
            }
        }
        return DP[x][y]=ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>DP(m,vector<int>(n,-1));
        int sum=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum=(sum+solve(i,j,grid,DP,m,n))%mod;
            }
        }

        return sum;
    }
};