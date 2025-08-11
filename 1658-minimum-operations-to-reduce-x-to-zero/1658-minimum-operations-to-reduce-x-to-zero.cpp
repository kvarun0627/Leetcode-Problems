class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int j=0;
        int sum=0;
        int ans=INT_MAX;
        int tot_sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(j<=i && tot_sum-sum<x)
            {
                sum-=nums[j];
                j++;
            }
            if(tot_sum-sum==x)
            {
                ans=min(ans,n-(i-j+1));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};