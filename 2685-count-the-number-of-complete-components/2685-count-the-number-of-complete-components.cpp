class Solution {
public:
    void construct_graph(vector<vector<int>>&gr ,vector<vector<int>>& edges, int n)
    {
        for(auto e:edges)
        {
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
    }
    bool BFS(vector<vector<int>>&gr ,int node ,vector<int>&vis)
    {
        int vertices=1;
        int edges=0;
        queue<int>q;
        q.push(node);
        vis[node]=true;

        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            for(int neigh:gr[n])
            {
                edges++;
                if(!vis[neigh])
                {
                    vertices++;
                    q.push(neigh);
                    vis[neigh]=true;
                }
            }
        }
        return edges==vertices*(vertices-1);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>gr(n);
        vector<int>vis(n,false);
        construct_graph(gr,edges,n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && BFS(gr,i,vis))
            {
                ans++;
            }
        }
        return ans;
    }
};