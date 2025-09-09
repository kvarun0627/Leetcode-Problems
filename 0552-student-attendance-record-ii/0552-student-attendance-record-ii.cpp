class Solution {
public:
    int mod=1e9+7;
    int memo(int n,int Acnt,int Lcnt,vector<vector<vector<int>>>&DP)
    {
        if(n==0)
        {
            return 1;
        }
        if(DP[n][Acnt][Lcnt]!=-1)
        {
            return DP[n][Acnt][Lcnt];
        }
        int ans=0;
        if(Acnt!=0)
        {
            ans=(ans+memo(n-1,Acnt-1,2,DP))%mod;
        }
        if(Lcnt!=0)
        {
            ans=(ans+memo(n-1,Acnt,Lcnt-1,DP))%mod;
        }
        ans=(ans+memo(n-1,Acnt,2,DP))%mod;
        return DP[n][Acnt][Lcnt]=ans;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>DP(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return memo(n,1,2,DP);
    }
};