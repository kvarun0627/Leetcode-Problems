class Solution {
public:
    long long reccur(vector<int>& prices, int k,int idx,int n,bool pending_trans,int buy,vector<vector<vector<vector<long long>>>>&DP)
    {
        if(k==0)
        {
            return 0;
        }
        if(idx==n)
        {
            if(!pending_trans)
            {
                return 0;
            }
            return -1e15;
        }

        if(DP[idx][k][pending_trans][buy+1]!=-1)
        {
            return DP[idx][k][pending_trans][buy+1];
        }
        long long not_take=reccur(prices,k,idx+1,n,pending_trans,buy,DP);
        long long take_buy=LLONG_MIN;
        long long take_sell=LLONG_MIN;
        if(!pending_trans)
        {
            take_buy=-prices[idx]+reccur(prices,k,idx+1,n,true,1,DP);
            take_sell=prices[idx]+reccur(prices,k,idx+1,n,true,0,DP);
        }
        else
        {
            if(buy)
            {
                take_sell=prices[idx]+reccur(prices,k-1,idx+1,n,false,-1,DP);
            }
            else
            {
                take_buy=-prices[idx]+reccur(prices,k-1,idx+1,n,false,-1,DP);
            }
        }
        return DP[idx][k][pending_trans][buy+1]=max({not_take,take_buy,take_sell});
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vector<vector<vector<vector<long long>>>>DP(n,vector<vector<vector<long long>>>(k+1,vector<vector<long long>>(2,vector<long long>(3,-1))));

        return reccur(prices,k,0,n,false,-1,DP);
    }
};