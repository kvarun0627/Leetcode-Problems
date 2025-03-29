class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;

        int l=0;
        int r=0;
        int n=nums.size();
        int prod=1;
        int ans=0;
        while(r<n)
        {
            prod=prod*nums[r];
            while(l<=r && prod>=k)
            {
                prod=prod/nums[l];
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
};