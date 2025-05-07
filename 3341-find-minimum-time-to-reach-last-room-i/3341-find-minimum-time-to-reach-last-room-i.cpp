class Solution {
public:

    typedef pair<pair<int,int>,int> pa;

    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

    bool is_valid(int i,int j,int n,int m)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int n=moveTime.size();
        int m=moveTime[0].size();

        priority_queue<pa,vector<pa>,greater<pa>>pq;

        pq.push({{0,0},0});

        vector<vector<int>>Time(n,vector<int>(m,INT_MAX));

        while(!pq.empty())
        {
            auto [coor,t]=pq.top();
            auto[x,y]=coor;
            pq.pop();

            if(x==n-1 && y==m-1) return t;

            for(auto d:dir)
            {
                int nx=x+d.first;
                int ny=y+d.second;
                if(is_valid(nx,ny,n,m))
                {
                    int t_move=max(moveTime[nx][ny]+1,t+1);
                    if(t_move<Time[nx][ny])
                    {
                        Time[nx][ny]=t_move;
                        pq.push({{nx,ny},t_move});
                    }
                }
            }
        }

        return -1;
    }
};
