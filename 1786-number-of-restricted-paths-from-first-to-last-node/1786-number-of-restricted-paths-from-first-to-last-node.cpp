class Solution {
public:
    typedef pair<int,int> pa;
    long long mod=1e9+7;
    void dijiktra(int n,vector<vector<pa>>&gr,vector<int>&distance)
    {
        priority_queue<pa,vector<pa>,greater<>>pq;
        pq.push({0,n-1});
        distance[n-1]=0;
        while(!pq.empty())
        {
            int curr_dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto [neighbour,wt]:gr[node])
            {
                if(distance[neighbour]>curr_dist+wt)
                {
                    distance[neighbour]=curr_dist+wt;
                    pq.push({curr_dist+wt,neighbour});
                }
            }
        }
    }
    int DP_DFS(vector<vector<pa>>&gr,vector<int>&DP,vector<bool>&vis,vector<int>&distance,int curr_node,int n)
    {
        vis[curr_node]=true;
        if(curr_node==n-1)
        {
            return 1;
        }
        if(DP[curr_node]!=-1)
        {
            return curr_node;
        }
        int ways=0;
        for(auto [neighbour,trash]:gr[curr_node])
        {
            if(!vis[neighbour] && distance[neighbour]<distance[curr_node])
            {
                ways=(ways+DP_DFS(gr,DP,vis,distance,neighbour,n))%mod;
            }
        }
        vis[curr_node]=false;
        return DP[curr_node]=ways%mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int>distance(n,INT_MAX);
        vector<vector<pa>>gr(n);
        for(vector<int>e :edges)
        {
            gr[e[0]-1].push_back({e[1]-1,e[2]});
            gr[e[1]-1].push_back({e[0]-1,e[2]});
        }

        dijiktra(n,gr,distance);

        vector<int>DP(n,-1);
        vector<bool>vis(n,false);
        return DP_DFS(gr,DP,vis,distance,0,n);

    }
};