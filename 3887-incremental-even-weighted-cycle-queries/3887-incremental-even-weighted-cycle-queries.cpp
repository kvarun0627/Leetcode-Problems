class Solution {
public:

    vector<int>par,rank,parity;
    pair<int,int> findParent(int u)
    {
        if(u == par[u])
        {
            return {u,0};
        }
        auto [p,pa] = findParent(par[u]);
        par[u] = p;
        parity[u] = parity[u] ^ pa;
        return {par[u] , parity[u]};
    }

    void Union(int u,int v,int w)
    {
        auto [parU , parityU] = findParent(u);
        auto [parV , parityV] = findParent(v);

        if(rank[parU] > rank[parV])
        {
            par[parV] = parU;
            parity[parV] = parityV ^ parityU ^ w;
        }
        else if(rank[parU] < rank[parV])
        {
            par[parU] = parV;
            parity[parU] = parityU ^ parityV ^ w;
        }
        else
        {
            par[parU] = parV;
            parity[parU] = parityU ^ parityV ^ w;
            rank[parV]++;
        }
    }

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) 
    {
        par.resize(n);
        rank.assign(n,0);
        parity.assign(n,0);
        for(int i=0 ; i<n ; i++)
        {
            par[i] = i;
        }

        int cnt = 0;
        for(auto e:edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2]%2;

            auto [parU , parityU] = findParent(u);
            auto [parV , parityV] = findParent(v);

            if(parU == parV )
            {
                if(!(parityU ^ parityV ^ w))
                {
                    cnt ++;
                }
            }
            else
            {
                Union(u,v,w);
                cnt++;
            }
        }

        return cnt;
    }
};