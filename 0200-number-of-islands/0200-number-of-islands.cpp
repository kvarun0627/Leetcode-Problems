class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    void BFS(vector<vector<char>>& grid,int x,int y,int m,int n)
    {
        queue<pair<int,int>>q;
        q.push({x,y});
        grid[x][y]='0';

        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop();
            for(auto [di,dj]:dir)
            {
                int ni=i+di;
                int nj=j+dj;
                if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]=='1')
                {
                    q.push({ni,nj});
                    grid[ni][nj]='0';
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    BFS(grid,i,j,m,n);
                }
            }
        }
        return ans;
    }
};