class Solution {
public:
    int N;
    vector<int>SPF;
    void build_SPF()
    {
        for(int i=0;i<=N;i++)
        {
            SPF[i]=i;
        }
        for(int i=2;i*i<=N;i++)
        {
            if(SPF[i]!=i) continue;
            for(int p=i*i;p<=N;p+=i)
            {
                if(SPF[p]==p)
                {
                    SPF[p]=i;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        N=*max_element(nums.begin(),nums.end());
        SPF.assign(N+1,0);
        build_SPF();

        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            while(num>1)
            {
                int p=SPF[num];
                while(p==SPF[num])
                {
                    num=num/p;
                }
                mp[p].push_back(i);
            }
        }

        queue<int>q;
        vector<int>dist(n,INT_MAX);
        q.push(0);
        dist[0]=0;
        unordered_set<int>st;
        while(!q.empty())
        {
            int idx=q.front();
            q.pop();

            if(idx==n-1) return dist[idx];

            if(idx+1<n && dist[idx+1]==INT_MAX)
            {
                dist[idx+1]=1+dist[idx];
                q.push(idx+1);
            }
            if(idx-1>=0 && dist[idx-1]==INT_MAX)
            {
                dist[idx-1]=1+dist[idx];
                q.push(idx-1);
            }
            if(SPF[nums[idx]]==nums[idx] && !st.count(nums[idx]))
            {
                for(int I:mp[nums[idx]])
                {
                    if(dist[I]==INT_MAX)
                    {
                        dist[I]=1+dist[idx];
                        q.push(I);
                    }
                }
                st.insert(nums[idx]);
            }
        }

        return -1;
    }
};