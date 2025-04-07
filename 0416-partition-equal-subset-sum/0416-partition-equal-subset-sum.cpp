class Solution {
public:
    bool subset_sum_equals_k(int n,int k,vector<vector<bool>>&dp,vector<int>&nums)
    {
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }

        if (nums[0] <= k) {
        dp[0][nums[0]] = true;
        }

        for(int idx=1;idx<n;idx++)
        {
            for(int target=1;target<=k;target++)
            {
                bool not_take=dp[idx-1][target];
                bool take=false;
                if(nums[idx]<=target)
                {
                    take=dp[idx-1][target-nums[idx]];
                } 
                dp[idx][target]= take | not_take; 
            }
        }

        return dp[n-1][k];
    }
    bool canPartition(vector<int>& nums) {

        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);

        if(tot%2) return false;

        int target=tot/2;

        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        return subset_sum_equals_k(n,target,dp,nums);
    }
};