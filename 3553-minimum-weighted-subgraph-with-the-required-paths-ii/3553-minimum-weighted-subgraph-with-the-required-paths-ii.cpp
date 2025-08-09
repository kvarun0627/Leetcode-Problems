class Solution {
public:
    int LOG=(int)ceil(log2((double)1e5));
    void construct_graph(vector<vector<pair<int,int>>>&Graph,vector<vector<int>>& edges)
    {
        for(auto e:edges)
        {
            Graph[e[0]].push_back({e[1],e[2]});
            Graph[e[1]].push_back({e[0],e[2]});
        }
    }
    void DFS(int root,int parent,vector<vector<pair<int,int>>>&Graph,vector<vector<int>>&UP,vector<int>&Depth,vector<int>&Path_sum)
    {
        UP[root][0]=parent;
        for(int j=1;j<=LOG;j++)
        {
            int mid=UP[root][j-1];
            if(mid==-1)
            {
                UP[root][j]=-1;
            }
            else
            {
                UP[root][j]=UP[mid][j-1];
            }
        }

        for(auto [V,Wt]:Graph[root])
            {
                if(V==parent) continue;

                Depth[V]=Depth[root]+1;
                Path_sum[V]=Path_sum[root]+Wt;
                DFS(V,root,Graph,UP,Depth,Path_sum);
            }
    }

    int Kth_ancestor(int u,vector<vector<int>>&UP,int k)
    {
        for(int j=0;j<=LOG;j++)
        {
            if(u==-1)
            {
                break;
            }
            if(k&(1<<j))
            {
                u=UP[u][j];
            }
        }
        return u;
    }

    int LCA(int u,int v,vector<vector<int>>&UP,vector<int>&Depth)
    {
        if(Depth[u]<Depth[v])
        {
            return LCA(v,u,UP,Depth);
        }

        u=Kth_ancestor(u,UP,Depth[u]-Depth[v]);

        if(u==v)
        {
            return u;
        }

        for (int j = LOG; j >= 0; j--) {
            if (UP[u][j] != UP[v][j]) {
                u = UP[u][j];
                v = UP[v][j];
            }
        }
        return UP[u][0];
    }
    int F(int a,int b,vector<vector<int>>&UP,vector<int>&Depth,vector<int>&Path_sum)
    {
        int u=LCA(a,b,UP,Depth);
        return Path_sum[a]+Path_sum[b]-2*Path_sum[u];
    }
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size();
        vector<vector<pair<int,int>>>Graph(n+1);
        construct_graph(Graph,edges);
        vector<vector<int>>UP(n+1,vector<int>(LOG+1,-1));
        vector<int>Depth(n+1,0);
        vector<int>Path_sum(n+1,0);
        DFS(0,-1,Graph,UP,Depth,Path_sum);
        vector<int>ans;
        for(auto Q:queries)
        {
            int src1=Q[0];
            int src2=Q[1];
            int dest=Q[2];

            int res=(F(src1,src2,UP,Depth,Path_sum)+F(src1,dest,UP,Depth,Path_sum)+F(src2,dest,UP,Depth,Path_sum))/2;
            ans.push_back(res);
        }
        return ans;
    }
};