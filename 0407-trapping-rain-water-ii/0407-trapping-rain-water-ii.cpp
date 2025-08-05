class Solution {
public:
    class cell{
        public:
            int height;
            int row;
            int col;

            cell(int height,int row,int col) : height(height),row(row),col(col) {}
            
            bool operator<(const cell&other)const{
                return height>=other.height;
            }
    };
    bool is_valid(int row,int col,int m,int n)
    {
        return row>=0 && row<m && col>=0 && col<n;
    }
    vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        priority_queue<cell>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            pq.push(cell(heightMap[0][i],0,i));
            pq.push(cell(heightMap[m-1][i],m-1,i));
            vis[0][i]=vis[m-1][i]=true;
        }
        for(int i=1;i<m-1;i++)
        {
            pq.push(cell(heightMap[i][0],i,0));
            pq.push(cell(heightMap[i][n-1],i,n-1));
            vis[i][0]=vis[i][n-1]=true;
        }

        int total_water=0;
        while(!pq.empty())
        {
            cell node=pq.top();
            pq.pop();

            for(auto [dx,dy]:dir)
            {
                int nx=node.row+dx;
                int ny=node.col+dy;
                if(is_valid(nx,ny,m,n) && !vis[nx][ny])
                {
                    if(heightMap[nx][ny]<node.height)
                    {
                        total_water+=abs(heightMap[nx][ny]-node.height);
                    }
                    pq.push(cell(max(node.height,heightMap[nx][ny]),nx,ny));
                    vis[nx][ny]=true;
                }
            }
        }
        return total_water;
    }
};