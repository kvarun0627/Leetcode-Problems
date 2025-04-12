class Solution {
public:
    int reccur(vector<int>&prices,vector<vector<int>>&DP,int cap,int idx,int n)
    {
        if(idx>=n) return 0;

        if(DP[idx][cap]!=-1) return DP[idx][cap];

        int skip=reccur(prices,DP,cap,idx+1,n);

        int buy=0;
        int sell=0;
        if(!cap)
        {
            buy=-prices[idx]+reccur(prices,DP,1,idx+1,n);
            DP[idx][cap]=max(buy,skip);
        }
        sell=prices[idx]+reccur(prices,DP,0,idx+2,n);
        DP[idx][cap]=max(skip,sell);

        return DP[idx][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>DP(n+2,vector<int>(2,0));
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
                    sell=prices[idx]+DP[idx+2][0];
                    DP[idx][cap]=max(skip,sell);
                }
            }
        }
        return DP[0][0];
    }
};