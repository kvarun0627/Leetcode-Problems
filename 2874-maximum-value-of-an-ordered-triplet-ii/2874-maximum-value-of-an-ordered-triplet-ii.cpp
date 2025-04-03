class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        long long imax=0;
        long long dmax=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dmax*nums[i]);
            imax=max(imax,(long long)nums[i]);
            dmax=max(dmax,(long long)imax-nums[i]);
        }
        return ans;
    }
};