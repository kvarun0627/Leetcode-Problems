class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        vector<int>suff(n+1,INT_MAX);
        for(int i=n-1;i>=0;i--)
        {
            suff[i]=min(suff[i+1],nums[i]);
        }

        long long ans=LONG_MIN;
        long long sum=0;
        for(int i=0;i<n-1;i++)
        {
            sum+=nums[i];
            int mini=suff[i+1];
            ans=max(ans,sum-(long long)mini);
        }
        return ans;
    }
};