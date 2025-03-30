class Solution {
public:
    int buy_and_sell_stock_tabulation(vector<vector<vector<int>>>&DP,vector<int>&prices,int n,int k)
    {
        for(int cap=0;cap<k;cap++)
        {
            for(int buy=0;buy<=1;buy++)
            {
                DP[n][buy][cap]=0;
            }
        }

        for(int idx=0;idx<=n;idx++)
        {
            for(int buy=0;buy<=1;buy++)
            {
                DP[idx][buy][0]=0;
            }
        }

        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    if(buy==1)
                    {
                        DP[idx][buy][cap]=max(-prices[idx]+DP[idx+1][0][cap],DP[idx+1][1][cap]);
                    }
                    else DP[idx][buy][cap]=max(prices[idx]+DP[idx+1][1][cap-1],DP[idx+1][0][cap]);
                }
            }
        }
        return DP[0][1][k];
    }
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>DP(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        return buy_and_sell_stock_tabulation(DP,prices,n,k);
    }
};