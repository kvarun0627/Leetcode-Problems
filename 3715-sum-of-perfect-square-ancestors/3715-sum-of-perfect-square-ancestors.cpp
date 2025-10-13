class Solution {
public:
    int N=1e5;
    vector<int>spf;
    void SPF()
    {
        for(int i=0;i<=N;i++)
        {
            spf[i]=i;
        }
        for(int i=2;i*i<=N;i++)
        {
            if(spf[i]!=i) continue;

            for(int p=i*i;p<=N;p+=i)
            {
                if(spf[p]==p)
                {
                    spf[p]=i;
                }
            }
        }
    }
    long long square_free_kernel(int x)
    {
        long long ans=1;
        while(x>1)
        {
            int p=spf[x];
            int cnt=0;
            while(x%p==0)
            {
                x/=p;
                cnt++;
            }

            if(cnt & 1)
            {
                ans*=(long long)p;
            }
        }
        return ans;
    }
    long long ans=0;
    unordered_map<long long ,int>mp;
    void DFS(int u, vector<vector<int>>&tree, vector<int>& nums)
    {
        long long sfk=square_free_kernel(nums[u]);
        ans+=mp[sfk];
        mp[sfk]++;
        for(int v:tree[u])
        {
            DFS(v,tree,nums);
        }
        mp[sfk]--;
    }
    void TREE(vector<vector<int>>&tree , vector<vector<int>>& edges)
    {
        for(auto e:edges)
        {
            tree[e[0]].push_back(e[1]);
        }
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        spf.assign(N+1,0);
        SPF();
        vector<vector<int>>tree(n);
        TREE(tree,edges);
        DFS(0,tree,nums);
        return ans;
    }
};