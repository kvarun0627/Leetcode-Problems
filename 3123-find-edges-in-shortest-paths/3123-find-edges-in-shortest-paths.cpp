class Solution {
public:

    vector<vector<pair<int,long long>>>adj;
    typedef pair<long long,int> pa;

    vector<long long> dijiktra(int node ,int n)
    {
        vector<long long>dist(n,INT_MAX);
        priority_queue<pa,vector<pa>,greater<pa>>pq;
        pq.push({0,node});
        dist[node] = 0;

        while(!pq.empty())
        {
            auto [Twt,u] = pq.top();
            pq.pop();

            for(auto [v,wt] : adj[u])
            {
                if(dist[v] > Twt + wt)
                {
                    dist[v] = Twt + wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) 
    {
        adj.resize(n);

        for(auto e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        
        vector<long long>dist1 = dijiktra(0,n);
        vector<long long>dist2 = dijiktra(n-1,n);

        vector<bool>ans;
        for(auto e:edges)
        {
            if(dist1[e[0]] != LLONG_MAX && dist2[e[1]]!=LLONG_MAX && dist1[e[0]] + dist2[e[1]] + e[2] == dist1[n-1])
            {
                ans.push_back(true);
            }
            else if(dist1[e[1]]!=LLONG_MAX && dist2[e[0]]!=LLONG_MAX && dist1[e[1]] + e[2] + dist2[e[0]] == dist1[n-1])
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};