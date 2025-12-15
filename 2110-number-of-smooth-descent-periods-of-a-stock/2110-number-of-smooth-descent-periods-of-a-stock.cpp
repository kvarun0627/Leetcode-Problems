class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) 
    {
        int n=prices.size();
        long long ans=0;
        int prev=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                prev=1;
                ans+=1;
                continue;
            }
            if(prices[i]==prices[i-1]-1)
            {
                prev+=1;
                ans+=prev;
            }
            else
            {
                prev=1;
                ans+=1;
            }

        }
        return ans;
    }
};