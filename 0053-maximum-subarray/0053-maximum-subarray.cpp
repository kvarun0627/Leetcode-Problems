class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        //DP
        // vector<int>DP(n,0);
        // DP[0]=nums[0];
        // int ans=DP[0];
        // for(int i=1;i<n;i++)
        // {
        //     DP[i]=max(DP[i-1]+nums[i],nums[i]);
        //     ans=max(DP[i],ans);
        // }
        // return ans;

        //space optimized
        int back=nums[0];
        int ans=back;
        for(int i=1;i<n;i++)
        {
            int curr=max(back+nums[i],nums[i]);
            ans=max(ans,curr);
            back=curr;
        }
        return ans;
    }
};