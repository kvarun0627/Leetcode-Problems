class Solution {
public:
    #define  pa pair<int,pair<int,int>>
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pa,vector<pa>,greater<>>q;
        health=health-grid[0][0];
        q.push({health,{0,0}});
        int X[4]={0,0,1,-1};
        int Y[4]={-1,1,0,0};
        vector<vector<int>>H(n,vector<int>(m,0));
        while(!q.empty())
        {
            int x=q.top().second.first;
            int y=q.top().second.second;
            int z=q.top().first;
            q.pop();
            if(x==n-1 && y==m-1)
            {
                return z>=1;
            }
            for(int i=0;i<4;i++)
            {
                int nx=x+X[i];
                int ny=y+Y[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    if(z-grid[nx][ny]>H[nx][ny])
                    {
                        q.push({z-grid[nx][ny],{nx,ny}});
                        H[nx][ny]=z-grid[nx][ny];
                    }
                }
            }
        }
        return false;
    }
};