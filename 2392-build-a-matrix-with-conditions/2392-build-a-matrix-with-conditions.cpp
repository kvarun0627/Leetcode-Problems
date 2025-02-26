class Solution {
public:
    vector<int>topological_sort(vector<vector<int>>edges,int k)
    {
        vector<vector<int>>gr(k+1);
        for(auto e : edges)
        {
            gr[e[0]].push_back(e[1]);
        }
        vector<int>indeg(k+1,0);
        for(int node=1;node<=k;node++)
        {
            for(int child:gr[node])
            {
                indeg[child]++;
            }
        }

        queue<int>q;
        vector<bool>vis(k+1,false);
        vector<int>topo;
        for(int node=1;node<=k;node++)
        {
            if(indeg[node]==0)
            {
                q.push(node);
                topo.push_back(node);
            }
        }
        
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int node=q.front();
                q.pop();
                vis[node]=true;
                for(int child:gr[node])
                {
                    if(!vis[child])
                    {
                        indeg[child]--;
                        if(indeg[child]==0)
                        {
                            q.push(child);
                            topo.push_back(child);
                        }
                    }
                    
                }
            }
        }

        return topo;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>row_topo=topological_sort(rowConditions,k);
        vector<int>col_topo=topological_sort(colConditions,k);

        if(row_topo.size()!=k || col_topo.size()!=k) return {};
        vector<vector<int>>matrix(k,vector<int>(k,0));
        map<int,int>col_idx;
        for(int i=0;i<col_topo.size();i++)
        {
            col_idx[col_topo[i]]=i;
        }
        for(int i=0;i<row_topo.size();i++)
        {
            matrix[i][col_idx[row_topo[i]]]=row_topo[i];
        }
        return matrix;
    }
};