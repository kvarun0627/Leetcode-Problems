class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},0});
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dist(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX)));
        dist[0][0][0]=0;
        vector<pair<int,int>>dir={{0,-1},{-1,0},{1,0},{0,1}};
        while(!q.empty())
        {
            auto [coor,obs]=q.front();
            q.pop();
            auto [x,y]=coor;
            for(auto [cx,cy]:dir)
            {
                int nx=x+cx;
                int ny=y+cy;

                if(!(nx>=0 && nx<m && ny>=0 && ny<n)) continue;

                if((grid[nx][ny]==1 && obs+1>k) || dist[nx][ny][obs+grid[nx][ny]]!=INT_MAX) continue;

                q.push({{nx,ny},obs+grid[nx][ny]});
                dist[nx][ny][obs+grid[nx][ny]]=dist[x][y][obs]+1;
            }
        }
        int ans=*min_element(dist[m-1][n-1].begin(),dist[m-1][n-1].end());
        return ans==INT_MAX?-1:ans;
    }
};