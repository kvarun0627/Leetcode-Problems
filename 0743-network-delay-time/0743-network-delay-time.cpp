class Solution {
public:
    typedef pair<int,int> pa;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector< pa >>adj(n);
        vector<int>Time(n,INT_MAX);

        for(auto I:times)
        {
            adj[I[0]-1].push_back({I[1]-1,I[2]});
        }

        priority_queue<pa,vector<pa>,greater<>>pq;
        pq.push({0,k-1});
        Time[k-1]=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int T=pq.top().first;
            pq.pop();
            for(auto [u,t]:adj[node])
            {
                if(Time[u]>T+t)
                {
                    pq.push({T+t,u});
                    Time[u]=T+t;
                }
            }
        }
        int ans=0;
        for(int i:Time)
        {
            if(i==INT_MAX) return -1;
            ans=max(i,ans);
        }
        return ans;
    }
};