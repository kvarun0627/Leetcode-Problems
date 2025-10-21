class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    bool BFS(int x,int y,vector<vector<int>>& grid, int k,int m,int n)
    {
        queue<pair<int,int>>q;
        q.push({x,y});
        long long sum=0;
        sum+=grid[x][y];
        grid[x][y]=0;
        while(!q.empty())
        {
            auto [cx,cy]=q.front();
            q.pop();

            for(auto [dx,dy]:dir)
            {
                int nx=cx+dx;
                int ny=cy+dy;
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=0)
                {
                    sum+=grid[nx][ny];
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
        }
        return sum % k == 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                {
                    ans+=BFS(i,j,grid,k,m,n);
                    cnt++;
                }
            }
        }
        cout<<cnt;
        return ans;
    }
};