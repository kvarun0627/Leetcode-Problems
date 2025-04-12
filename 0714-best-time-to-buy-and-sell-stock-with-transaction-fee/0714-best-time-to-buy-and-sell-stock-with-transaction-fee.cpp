class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>DP(n+1,vector<int>(2,0));
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int cap=0;cap<=1;cap++)
            {
                int buy=0;
                int sell=0;
                int skip=DP[idx+1][cap];
                if(!cap)
                {
                    buy=-prices[idx]+DP[idx+1][1];
                    DP[idx][cap]=max(buy,skip);
                }
                else
                {
                    sell=prices[idx]-fee+DP[idx+1][0];
                    DP[idx][cap]=max(skip,sell);
                }
            }
        }
        return DP[0][0];
    }
};