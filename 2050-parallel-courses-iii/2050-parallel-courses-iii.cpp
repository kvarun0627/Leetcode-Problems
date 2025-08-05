class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        vector<int>ans(n,0);
        queue<int>q;
        for(auto r:relations)
        {
            adj[r[0]-1].push_back(r[1]-1);
            indeg[r[1]-1]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans[node]+=time[node];

            for(int v:adj[node])
            {
                indeg[v]--;
                ans[v]=max(ans[v],ans[node]);
                if(indeg[v]==0)
                {
                    q.push(v);
                }
            }
        }

        return *max_element(ans.begin(),ans.end());
    }
};