class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0 && i<m && j>=0 && j<n;
    }
    void BFS(vector<vector<char>>& grid,int i,int j,int m,int n)
    {
        queue<pair<int,int>>q;
        grid[i][j]='0';
        q.push({i,j});
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(auto d:dir)
            {
                int nx=x+d.first;
                int ny=y+d.second;
                if(isValid(nx,ny,m,n) && grid[nx][ny]=='1')
                {
                    q.push({nx,ny});
                    grid[nx][ny]='0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    BFS(grid,i,j,m,n);
                    ans++;
                }
            }
        }
        return ans;
    }
};