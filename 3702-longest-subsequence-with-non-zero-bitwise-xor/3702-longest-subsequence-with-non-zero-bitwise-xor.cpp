class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool zer0=true;
        int n=nums.size();
        int xr=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                zer0=false;
            }
            xr^=nums[i];
        }
        if(xr==0)
        {
            return zer0?0:n-1;
        }
        return n;
    }
};