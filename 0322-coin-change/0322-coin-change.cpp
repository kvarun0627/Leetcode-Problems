class Solution {
public:

    //memoization
    // int DP_Memo(vector<int>& coins, int amount, int idx, vector<vector<int>>&DP)
    // {
    //     if(amount==0) return 0;

    //     if(idx==0)
    //     {
    //         return amount==0?0:1e9;
    //     }

    //     if(DP[idx][amount]!=-1) return DP[idx][amount];

    //     int take=INT_MAX;
    //     if(coins[idx-1]<=amount)
    //     {
    //         take=1+DP_Memo(coins,amount-coins[idx-1],idx,DP);
    //     }
    //     int not_take=DP_Memo(coins,amount,idx-1,DP);

    //     return DP[idx][amount]=min(take,not_take);
    // }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();


        //tabulation
        // vector<vector<int>>DP(n+1,vector<int>(amount+1,0));
        // for(int i=1;i<=amount;i++)
        // {
        //     DP[0][i]=1e9;
        // }

        // for(int idx=1;idx<=n;idx++)
        // {
        //     for(int j=0;j<=amount;j++)
        //     {
        //         int take=INT_MAX;
        //         if(coins[idx-1]<=j)
        //         {
        //             take=1+DP[idx][j-coins[idx-1]];
        //         }
        //         int not_take=DP[idx-1][j];
        //         DP[idx][j]=min(take,not_take);
        //     }
        // }
        // int ans=DP[n][amount];
        // return ans>=1e9?-1:ans;

        //space optimization
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);

        for(int i=1;i<=amount;i++)
        {
            prev[i]=1e9;
        }

        for(int idx=1;idx<=n;idx++)
        {
            for(int j=0;j<=amount;j++)
            {
                int take=INT_MAX;
                if(coins[idx-1]<=j)
                {
                    take=1+curr[j-coins[idx-1]];
                }
                int not_take=prev[j];
                curr[j]=min(take,not_take);
            }
            prev=curr;
        }
        int ans=prev[amount];
        return ans>=1e9?-1:ans;
    }
};