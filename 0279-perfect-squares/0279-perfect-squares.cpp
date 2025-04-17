class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>>q;
        vector<bool>vis(n+1,false);
        q.push({n,0});
        vis[n]=true;

        while(!q.empty())
        {
            auto[node,lvl]=q.front();
            q.pop();

            if(node==0) return lvl;

            for(int i=1;i*i<=node;i++)
            {
                if(node-i*i>=0 && !vis[node-i*i])
                {
                    q.push({node-i*i,lvl+1});
                    vis[node-i*i]=true;
                }
            }
        }
        return -1;
    }
};