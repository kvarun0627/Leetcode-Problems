class Solution {
public:
    int mod=1e9+7;
    // int memo(int n, int idx,int target,vector<int>&group,vector<int>&profit,int m,vector<vector<vector<int>>>&DP)
    // {
    //     if(idx==m)
    //     {
    //         return target==0;
    //     }
    //     if(DP[idx][n][target]!=-1)
    //     {
    //         return DP[idx][n][target];
    //     }
    //     int skip=memo(n,idx+1,target,group,profit,m,DP);
    //     int not_skip=0;
    //     if(group[idx]<=n)
    //     {
    //         not_skip=memo(n-group[idx],idx+1,max(0,target-profit[idx]),group,profit,m,DP);
    //     }
    //     return DP[idx][n][target]=(skip+not_skip)%mod;
    // }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=group.size();
        vector<vector<vector<int>>>DP(m+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,0)));
        for(int idx=0;idx<=n;idx++)
        {
            DP[m][idx][0]=1;
        }
        for(int idx=m-1;idx>=0;idx--)
        {
            for(int target=0;target<=minProfit;target++)
            {
                for(int num=0;num<=n;num++)
                {
                    int skip=DP[idx+1][num][target];
                    int not_skip=0;
                    if(group[idx]<=num)
                    {
                        not_skip=DP[idx+1][num-group[idx]][max(0,target-profit[idx])];
                    }
                    DP[idx][num][target]=(skip+not_skip)%mod;
                }
            }
        }
        return DP[0][n][minProfit];
        // return memo(n,0,minProfit,group,profit,m,DP);
    }
};