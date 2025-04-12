class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int j=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[j])
            {
                ans+=(long long)(i-j)*nums[j];
                j=i;
            }
        }
        ans+=(long long)(n-1-j)*nums[j];
        return ans;
    }
};