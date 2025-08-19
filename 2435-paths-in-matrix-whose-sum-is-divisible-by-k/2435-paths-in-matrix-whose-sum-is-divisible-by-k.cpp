class Solution {
public:
    int MOD=1e9+7;
    int memo(int x,int y, vector<vector<int>>& grid, int mod, int m, int n,int k, vector<vector<vector<int>>>&DP)
    {
        if(x==m-1 && y==n-1)
        {
            return (mod+grid[x][y])%k==0;
        }
        if(DP[x][y][mod]!=-1)
        {
            return DP[x][y][mod];
        }
        int down=0;
        int right=0;
        if(x+1<m)
        {
            down=memo(x+1,y,grid,(mod+grid[x][y])%k,m,n,k,DP);
        }
        if(y+1<n)
        {
            right=memo(x,y+1,grid,(mod+grid[x][y])%k,m,n,k,DP);
        }
        return DP[x][y][mod]=(right+down)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>DP(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return memo(0,0,grid,0,m,n,k,DP);
    }
};