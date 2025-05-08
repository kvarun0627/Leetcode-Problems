class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>pref(n+1, 0);
        for (int i=0;i<n;i++)
        {
            pref[i+1]=pref[i]+nums[i];
        } 
           
        vector<vector<int>>dp(n+1,vector<int>(4,INT_MIN));
        dp[n][0]=0;
        
        for (int idx=n-1; idx>=0;--idx) {

            for (int j=0;j<=3;++j) {

                dp[idx][j]=max(dp[idx][j],dp[idx+1][j]);
                if (j>0 && idx+k<=n) 
                {
                    dp[idx][j]=max(dp[idx][j],pref[idx+k]-pref[idx]+dp[idx+k][j-1]);
                }
            }
        }
        
        vector<int>ans;
        int i=0;int j=3;
        while(i<n && j>0)
        {
            int skip=dp[i+1][j];
            int not_skip=INT_MIN;
            if(i+k<=n)
            {
                not_skip=pref[i+k]-pref[i]+dp[i+k][j-1];
            }
            if(not_skip>=skip)
            {
                ans.push_back(i);
                i=i+k;
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
