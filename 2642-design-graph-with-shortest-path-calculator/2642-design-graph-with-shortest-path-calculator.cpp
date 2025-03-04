class Graph {
public:
    vector<vector<pair<int,int>>>adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj=vector<vector<pair<int,int>>>(n);
        for(vector<int>e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(101,INT_MAX);
        priority_queue<pair<int,int>>pq;
        dist[node1]=0;
        pq.push({0,node1});
        while(!pq.empty())
        {
            int n=pq.top().second;
            int curr_wt=pq.top().first;
            pq.pop();
            for(auto [node , wt]:adj[n])
            {
                if(dist[node]>curr_wt+wt)
                {
                    pq.push({curr_wt+wt,node});
                    dist[node]=curr_wt+wt;
                }
            }
        }
        return dist[node2]==INT_MAX?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */