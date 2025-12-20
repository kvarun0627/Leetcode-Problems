class Solution {
public:
    vector<int>par;
    int find_parent(int u)
    {
        if(u==par[u])
        {
            return u;
        }
        //path compression
        par[u]=find_parent(par[u]);
        return par[u];
    };
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        auto cmp=[&](vector<int>&a,vector<int>&b)
        {
            return a[2]<b[2];
        };
        sort(meetings.begin(),meetings.end(),cmp);
        
        par.resize(n);
        vector<int>rank(n,0);
        
        auto Union=[&](int u,int v)
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
        };

        vector<bool>hasSecret(n,false);
        hasSecret[0]=hasSecret[firstPerson]=true;
        for(int i=0;i<n;i++)
        {
          par[i]=i;
        }
        int m=meetings.size();
        for(int i=0;i<m;)
        {
            int j=i;
            int time=meetings[i][2];
            set<int>people;
            set<int>comp;
            while(j<m && meetings[j][2]==time)
            {
                Union(meetings[j][0],meetings[j][1]);
                people.insert(meetings[j][0]);
                people.insert(meetings[j][1]);
                j++;
            }

            for(auto it=people.begin();it!=people.end();it++)
            {
                int p=*it;
                int ID=find_parent(p);
                if(hasSecret[p])
                {
                    comp.insert(ID);
                }
            }

            for(auto it=people.begin();it!=people.end();it++)
            {
                int p=*it;
                int ID=find_parent(p);
                if(comp.count(ID))
                {
                    hasSecret[p]=true;
                }
            }

            for(auto it=people.begin();it!=people.end();it++)
            {
                int p=*it;
                par[p]=p;
                rank[p]=0;
            }

            i=j;
        }

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(hasSecret[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};