class TreeAncestor {
public:
    int height=(int)log2((double)1e5);
    vector<vector<int>>UP;
    void construct_Tree(vector<int>&parent,int n,vector<vector<int>>&Tree)
    {
        for(int i=1;i<n;i++)
        {
            Tree[parent[i]].push_back(i);
            Tree[i].push_back(parent[i]);
        }
    }

    void DFS(vector<vector<int>>&UP, int node, int Parent, vector<vector<int>>&Tree)
    {
        UP[node][0]=Parent;
        for(int i=1;i<height;i++)
        {
            int mid=UP[node][i-1];
            if(mid==-1)
            {
                UP[node][i]=-1;
            }
            else
            {
                UP[node][i]=UP[UP[node][i-1]][i-1];   
            }
        }
        for(int V:Tree[node])
        {
            if(V!=Parent)
            {
                DFS(UP,V,node,Tree);   
            }
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>>Tree(n);
        construct_Tree(parent,n,Tree);
        UP=vector<vector<int>>(n,vector<int>(height));
        DFS(UP,0,-1,Tree);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<height;i++)
        {
            if(k & (1<<i))
            {
                node=UP[node][i];
                if(node==-1)
                {
                    break;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */