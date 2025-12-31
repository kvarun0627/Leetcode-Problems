class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>time(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    time[i][j]=0;
                }
            }
        }

        vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(auto [cx,cy]:dir)
            {
                int nx=x+cx;
                int ny=y+cy;
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0 && time[nx][ny]>time[x][y]+1)
                {
                    q.push({nx,ny});
                    time[nx][ny]=time[x][y]+1;
                }
            }
        }

        auto check=[&](int T)
        {
            vector<vector<bool>>vis(n,vector<bool>(m,false));
            queue<pair<pair<int,int>,int>>q;
            if(T<time[0][0])
            {
                q.push({{0,0},T});
                vis[0][0]=true;
            }
            while(!q.empty())
            {
                auto [coor,t]=q.front();
                auto [x,y]=coor;
                q.pop();
                if(x==n-1 && y==m-1)
                {
                    return true;
                }
                for(auto [cx,cy]:dir)
                {
                    int nx=x+cx;
                    int ny=y+cy;
                    if(nx>=0 && ny>=0 && nx<n && ny<m)
                    {
                        if (grid[nx][ny] == 0 && !vis[nx][ny])
                        {
                            if (nx == n-1 && ny == m-1) 
                            {
                                if(time[nx][ny] >= t+1) 
                                {
                                    return true;
                                }
                            } 
                            else if (time[nx][ny] > t+1) 
                            {
                                q.push({{nx, ny}, t+1});
                                vis[nx][ny] = true;
                            }
                        }
                    }
                }
            }
            return false;
        };
        int high=1e9;
        int low=0;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};