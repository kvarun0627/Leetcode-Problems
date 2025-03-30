class Solution {
public:
    int buy_and_sell_stock(vector<vector<vector<int>>>&DP,vector<int>&prices,int buy,int cap,int idx,int n)
    {
        if(idx==n || cap==0)
        {
            return 0;
        }
        if(DP[idx][buy][cap]!=-1)
        {
            return DP[idx][buy][cap];
        }
        if(buy)
        {
            return DP[idx][buy][cap]=max(-prices[idx]+buy_and_sell_stock(DP,prices,0,cap,idx+1,n),buy_and_sell_stock(DP,prices,1,cap,idx+1,n));
        }
        return DP[idx][buy][cap]=max(prices[idx]+buy_and_sell_stock(DP,prices,1,cap-1,idx+1,n),buy_and_sell_stock(DP,prices,0,cap,idx+1,n));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>DP(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return buy_and_sell_stock(DP,prices,1,2,0,n);
    }
};