class Solution {
public:
    void create_graph(int n,vector<vector<int>>& edges,vector<vector<pair<int,int>>> &adj)
    {
        for(auto v:edges)
        {
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
    }
    int BFS(vector<vector<pair<int,int>>> &adj,vector<int> &componentID,vector<int> &visited,int node,int ID)
    {
        visited[node]=true;
        queue<int>q;
        q.push(node);
        int cost=INT_MAX;
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            componentID[n]=ID;
            for(auto [next,wt]:adj[n])
            {
                cost&=wt;
                if(!visited[next])
                {
                    visited[next]=true;
                    q.push(next);
                }
            }
        }
        return cost;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        vector<vector<pair<int,int>>>adj(n);
        create_graph(n,edges,adj);

        vector<int>componentID(n,-1);
        vector<int>connectedComponentCost(n,0);
        vector<int>visited(n,false);

        for(int node=0;node<n;node++)
        {
            if(!visited[node])
            {
                connectedComponentCost[node]=BFS(adj,componentID,visited,node,node);
            }
        }
        vector<int>query_ans;
        for(auto q:query)
        {
            if(componentID[q[0]]==componentID[q[1]])
            {
                query_ans.push_back(connectedComponentCost[componentID[q[0]]]);
            }
            else
            {
                query_ans.push_back(-1);
            }
        }
        return query_ans;
    }
};