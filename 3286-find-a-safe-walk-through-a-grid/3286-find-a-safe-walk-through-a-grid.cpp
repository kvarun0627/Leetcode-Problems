class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        health=health-grid[0][0];
        q.push({{0,0},health});
        grid[0][0]=-1;
        int X[4]={0,0,1,-1};
        int Y[4]={-1,1,0,0};
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int z=q.front().second;
            q.pop();
            if(x==n-1 && y==m-1)
            {
                return z>=1;
            }
            for(int i=0;i<4;i++)
            {
                int nx=x+X[i];
                int ny=y+Y[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!=-1)
                {
                    if(z-grid[nx][ny]>=1)
                    {
                        q.push({{nx,ny},z-grid[nx][ny]});
                        grid[nx][ny]=-1;
                    }
                }
            }
        }
        return false;
    }
};