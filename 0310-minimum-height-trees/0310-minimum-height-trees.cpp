class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        {
            return {0};
        }
        vector<vector<int>>gr(n);
        vector<int>deg(n);

        for(auto e:edges)
        {
            deg[e[0]]++;
            deg[e[1]]++;
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }

        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1)
            {
                q.push(i);
            }
        }

        while(n>2)
        {
            int s=q.size();
            n-=s;
            while(s--)
            {
                int leaf=q.front();
                q.pop();
                deg[gr[leaf][0]]--;
                if(deg[gr[leaf][0]]==1)
                {
                    q.push(gr[leaf][0]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};