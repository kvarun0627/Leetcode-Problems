class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>dist(n,n-1);
        vector<vector<int>>gr(n);
        for(int i=0;i<n-1;i++)
        {
            gr[i].push_back(i+1);
            dist[i]=i;
        }

        auto BFS=[&](int u)
        {
            queue<int>q;
            q.push(u);
            while(!q.empty())
            {
                int node=q.front();q.pop();
                for(int v:gr[node])
                {
                    if(dist[v]>1+dist[node])
                    {
                        q.push(v);
                        dist[v]=1+dist[node];
                    }
                }
            }
        };

        vector<int>ans;
        for(auto q:queries)
        {
            gr[q[0]].push_back(q[1]);
            BFS(q[0]);
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};