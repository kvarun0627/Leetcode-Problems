class Solution {
public:
    //memoization
    // int memo(int idx,vector<int>& nums, int k, vector<int>&DP, int n)
    // {
    //     if(idx==n)
    //     {
    //         return 0;
    //     }
    //     if(DP[idx]!=-1)
    //     {
    //         return DP[idx];
    //     }

    //     unordered_map<int,int>mp;
    //     int cnt=0;
    //     int ans=INT_MAX;
    //     int trimmed=0;
    //     for(int i=idx;i<n;i++)
    //     {
    //         mp[nums[i]]++;
    //         if(mp[nums[i]]==1)
    //         {
    //             cnt++;
    //         }
    //         else if(mp[nums[i]]==2)
    //         {
    //             cnt--;
    //         }
    //         trimmed=i-idx+1-cnt;
    //         ans=min(ans,k+trimmed+memo(i+1,nums,k,DP,n));
    //     }
    //     return DP[idx]=ans;
    // }
    int minCost(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>DP(n+1,0);
        for(int idx=n-1;idx>=0;idx--)
        {
            unordered_map<int,int>mp;
            int cnt=0;
            int ans=INT_MAX;
            int trimmed=0;
            for(int i=idx;i<n;i++)
            {
                mp[nums[i]]++;
                if(mp[nums[i]]==1)
                {
                    cnt++;
                }
                else if(mp[nums[i]]==2)
                {
                    cnt--;
                }
                trimmed=i-idx+1-cnt;
                ans=min(ans,k+trimmed+DP[i+1]);
            }
            DP[idx]=ans;
        }
        return DP[0];
    }
};