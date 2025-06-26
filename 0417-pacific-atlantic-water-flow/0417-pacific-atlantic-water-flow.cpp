class Solution {
public:
    bool is_valid(int n,int m,int x,int y)
    {
        return x>=0 && x<n && y>=0 && y<m;
    }
    vector<pair<int,int>>dir={{0,1},{-1,0},{0,-1},{1,0}};
    void BFS(queue<pair<int,int>>&q, vector<vector<int>>& heights,vector<vector<bool>> &vis, int n, int m)
    {
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:dir)
            {
                int nx=x+dx;
                int ny=y+dy;

                if(!is_valid(n,m,nx,ny) || heights[nx][ny]<heights[x][y]) continue;

                if(!vis[nx][ny])
                {
                    q.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n,m;
        n=heights.size();
        m=heights[0].size();

        vector<vector<bool>>pacific_vis(n,vector<bool>(m,false)),atlantic_vis(n,vector<bool>(m,false));

        queue<pair<int,int>>pacific_q,atlantic_q;
        for(int i=0;i<n;i++)
        {
            pacific_q.push({i,0});
            pacific_vis[i][0]=true;
            atlantic_q.push({i,m-1});
            atlantic_vis[i][m-1]=true;
        }

        for(int i=0;i<m;i++)
        {
            pacific_q.push({0,i});
            pacific_vis[0][i]=true;
            atlantic_q.push({n-1,i});
            atlantic_vis[n-1][i]=true;
        }

        BFS(pacific_q,heights,pacific_vis,n,m);
        BFS(atlantic_q,heights,atlantic_vis,n,m);

        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(atlantic_vis[i][j] && pacific_vis[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};