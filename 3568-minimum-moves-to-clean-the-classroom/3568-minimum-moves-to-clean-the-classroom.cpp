class Solution {
public:
    unordered_map<int,unordered_map<int,int>>pos;
    vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    int minMoves(vector<string>& classroom, int energy) {

        int sx;int sy;
        int litres=0;
        int m=classroom.size();
        int n=classroom[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(classroom[i][j]=='S')
                {
                    sx=i;sy=j;
                }
                if(classroom[i][j]=='L')
                {
                    pos[i][j]=litres;
                    litres++;
                }
            }
        }
        
        int org_mask=(1<<litres)-1;
        vector<vector<vector<vector<int>>>>dist(m,vector<vector<vector<int>>>(n,vector<vector<int>>(energy+1,vector<int>(org_mask+1,-1))));

        queue<tuple<int,int,int,int>>q;
        q.push({sx,sy,energy,org_mask});
        dist[sx][sy][energy][org_mask]=0;
        int mini=INT_MAX;

        while(!q.empty())
        {
            auto [x,y,e,mask]=q.front();
            q.pop();
            if(mask==0)
            {
                mini=min(mini,dist[x][y][e][mask]);
            }
            if(e==0) continue;

            for(pair<int,int>&p:dir)
            {
                int nx=x+p.first;
                int ny=y+p.second;
                if(nx<0 || nx>=m || ny<0 || ny>=n || classroom[nx][ny]=='X') continue;

                int newmask=mask;
                int new_e=e-1;
                if(classroom[nx][ny]=='L')
                {
                    int p=pos[nx][ny];
                    newmask = newmask & ~(1<<p);
                }
                if(classroom[nx][ny]=='R')
                {
                    new_e=energy;
                }

                if(dist[nx][ny][new_e][newmask]==-1)
                {
                    dist[nx][ny][new_e][newmask]=1+dist[x][y][e][mask];
                    q.push({nx,ny,new_e,newmask});
                }
            }
        }

        return mini==INT_MAX?-1:mini;
    }
};