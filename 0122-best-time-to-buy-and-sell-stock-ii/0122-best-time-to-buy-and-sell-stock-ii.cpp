class Solution {
public:
    int solve(vector<int>&prices,int buy,int curr_idx,vector<vector<int>>&DP)
    {
        if(curr_idx==prices.size())
        {
            return 0;
        }

        if(DP[curr_idx][buy]!=-1)
        {
            return DP[curr_idx][buy];
        }
        if(buy)
        {
            int sell = prices[curr_idx] + solve(prices,0,curr_idx+1 , DP);
            int not_sell=solve(prices,1,curr_idx+1,DP);
            return DP[curr_idx][buy]=max(sell,not_sell);
        }

        int buy_stock= -prices[curr_idx] +solve(prices,1,curr_idx+1,DP);
        int not_buy=solve(prices,0,curr_idx+1,DP);
        return DP[curr_idx][buy]=max(buy_stock,not_buy);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>DP(n,vector<int>(2,-1));
        return solve(prices,0,0,DP);
    }
};