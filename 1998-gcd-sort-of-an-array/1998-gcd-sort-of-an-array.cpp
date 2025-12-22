class Solution {
public:
    vector<int>SPF;
    void build_SPF(int n)
    {
        for(int i=0;i<=n;i++)
        {
            SPF[i]=i;
        }
        for(int i=2;i*i<=n;i++)
        {
            if(SPF[i]==i)
            {
                for(int p=i*i;p<=n;p+=i)
                {
                    if(SPF[p]==p)
                    {
                        SPF[p]=i;
                    }
                }
            }
        }
    }

    vector<int>par;
    vector<int>rank;
    int find_parent(int u)
    {
        if(u==par[u])
        {
            return u;
        }
        //path compression
        return par[u]=find_parent(par[u]);
    }
    void Union(int u,int v)
    {
        int par_u=find_parent(u);
        int par_v=find_parent(v);

        if(rank[par_u]>rank[par_v])
        {
            par[par_v]=par_u;
        }        
        else if(rank[par_u]<rank[par_v])
        {
            par[par_u]=par_v;
        }
        else
        {
            par[par_u]=par_v;
            rank[par_v]++;
        }
    }
    bool same_component(int u,int v)
    {
        int par_u=find_parent(u);
        int par_v=find_parent(v);
        return par_u == par_v ;
    }
    bool gcdSort(vector<int>& nums) 
    {
        int N=1e5;
        SPF.resize(N+1);
        build_SPF(N);

        int n=nums.size();
        vector<pair<int,int>>copy;
        for(int i=0;i<n;i++)
        {
            copy.push_back({nums[i],i});
        }
        sort(copy.begin(),copy.end());

        par.resize(n);
        rank.assign(n,0);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        unordered_map<int,int>prime_idx;
        for(int i=0;i<n;i++)
        {
            int m=nums[i];
            while(m>1)
            {
                int p=SPF[m];
                while(SPF[m]==p)
                {
                    m/=p;
                }

                if(prime_idx.find(p)!=prime_idx.end())
                {
                    Union(prime_idx[p],i);
                }
                prime_idx[p]=i;
            }
        }

        for(int i=0;i<n;i++)
        {
            int s_idx=copy[i].second;
            if(!same_component(i,s_idx))
            {
                return false;
            }
        }

        return true;
    }
};