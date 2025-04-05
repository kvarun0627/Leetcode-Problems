class Solution {
public:
    int mod=1e9+7;
    int DP_memo(vector<vector<int>>& grid, int k,int x,int y,int val,int m,int n, vector<vector<vector<int>>>& DP)
    {   
        val^=grid[x][y];
        if(x==m-1 && y==n-1) return val==k?1:0;

        if(DP[x][y][val]!=-1) return DP[x][y][val];

        int right=0;int down=0;
        
        if(x+1<m)
        {
            down=DP_memo(grid,k,x+1,y,val,m,n,DP)%mod;
        }
        if(y+1<n)
        {
            right=DP_memo(grid,k,x,y+1,val,m,n,DP);
        }
        return DP[x][y][val]=right+down;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>DP(m,vector<vector<int>>(n,vector<int>(16,-1)));
        return DP_memo(grid,k,0,0,0,m,n,DP);
    }
};