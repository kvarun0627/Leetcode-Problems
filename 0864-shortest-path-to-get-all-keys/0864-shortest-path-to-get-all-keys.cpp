class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        unordered_map<string,int>dist;
        int k=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='@')
                {
                    q.push({{i,j},0});
                    string state=to_string(i)+" "+to_string(j)+" "+to_string(0);
                    dist[state]=0;
                }
                if(grid[i][j]>='a' && grid[i][j]<='f')
                {
                    k++;
                }
            }
        }
        vector<pair<int,int>>dir={{0,1},{-1,0},{0,-1},{1,0}};
        while(!q.empty())
        {
            auto [coor,keys]=q.front();
            q.pop();

            auto [x,y]=coor;
            string state=to_string(x)+" "+to_string(y)+" "+to_string(keys);
            if(keys==((1<<k)-1))
            {
                return dist[state];
            }
            
            for(auto [cx,cy]:dir)
            {
                int nx=x+cx;
                int ny=y+cy;
                string cur_state=to_string(nx)+" "+to_string(ny)+" "+to_string(keys);
                if(!(nx>=0 && nx<m && ny>=0 && ny<n) || grid[nx][ny]=='#' || dist.find(cur_state)!=dist.end()) continue;

                if(grid[nx][ny]>='A' && grid[nx][ny]<='F')
                {
                    int idx=grid[nx][ny]-'A';
                    if(keys & (1<<idx))
                    {
                        q.push({{nx,ny},keys});
                        dist[cur_state]=dist[state]+1;
                    }
                }
                else if(grid[nx][ny]>='a' && grid[nx][ny]<='f')
                {
                    int idx=grid[nx][ny]-'a';
                    int new_keys= (keys | (1<<idx));
                    string new_state=to_string(nx)+" "+to_string(ny)+" "+to_string(new_keys);

                    if(dist.find(new_state)!=dist.end()) continue;
                    
                    q.push({{nx, ny},new_keys});
                    dist[new_state]=dist[state]+1;
                }
                else
                {
                    q.push({{nx, ny},keys});
                    dist[cur_state]=dist[state]+1;
                }
            }
        }
        return -1;
    }
};