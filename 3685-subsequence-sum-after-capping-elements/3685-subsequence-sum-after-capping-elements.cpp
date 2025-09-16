class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<vector<bool>>DP(n+1,vector<bool>(k+1,false));
        for(int idx=0;idx<=n;idx++)
        {
            DP[idx][0]=true;
        }
        for(int idx=1;idx<=n;idx++)
        {
            for(int sum=0;sum<=k;sum++)
            {
                if(sum<arr[idx-1])
                {
                    DP[idx][sum]=DP[idx-1][sum];
                }
                else
                {
                    DP[idx][sum]=DP[idx-1][sum] || DP[idx-1][sum-arr[idx-1]];
                }
            }
        }

        vector<bool>ans(n,false);
        int idx=0;
        for(int x=1;x<=n;x++)
        {
            while(idx<n && arr[idx]<x)
            {
                idx++;
            }
            int s=n-idx;
            for(int sum=0;sum<=k;sum++)
            {
                if(DP[idx][sum])
                {
                    int rem_sum=k-sum;
                    if(rem_sum%x==0 && rem_sum/x<=s)
                    {
                        ans[x-1]=true;
                    }
                }
                if(ans[x-1])
                {
                    break;
                }
            }
        }
        return ans;
    }
};