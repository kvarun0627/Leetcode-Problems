class Solution {
public:
 #define cell pair<int,pair<int,int>>
    bool check(int i,int j,int n)
    {
        return i>=0 && i<n && j>=0 && j<n;
    }

    vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};

    int swimInWater(vector<vector<int>>& grid) {

        priority_queue<cell,vector<cell>,greater<>>q;
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        q.push({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];

        while(!q.empty())
        {
            auto [t, pos] = q.top();
            auto [x, y] = pos;
            q.pop();
            if(x==n-1 && y==n-1)
            {
                return t;
            }
            for(auto d:dir)
            {
                int nx=x+d.first;
                int ny=y+d.second;
                if(check(nx,ny,n))
                {
                    int new_time=max(grid[nx][ny],t);
                    if(dist[nx][ny]>new_time)
                    {
                        q.push({new_time,{nx,ny}});
                        dist[nx][ny]=new_time;
                    }
                }
            }
        }
        return -1;
    }
};