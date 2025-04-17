class Solution {
public:
    int mod=1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        // if(target==0)
        // {
        //     return n==0?1:0;
        // }

        // if(!DP[n][target]!=-1) return DP[n][target];

        // int ans=0;
        // for(int i=target;i>=0;i--)
        // {
        //     ans=(ans+numRollsToTarget(n-1,k,i))%mod;
        // }
        // return DP[n][target]=ans%mod;

        // vector<vector<int>>DP(n+1,vector<int>(target+1,0));
        vector<int>curr(target+1,0);
        vector<int>prev(target+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++)
        {
            fill(curr.begin(), curr.end(), 0);
            for(int l=1;l<=target;l++)
            {
                for(int j=1;j<=k;j++)
                {
                    if(l-j>=0)
                    {
                        curr[l]=(curr[l]+prev[l-j])%mod;
                    }
                }
            }
            prev=curr;
        }
        return prev[target]%mod;
    }
};