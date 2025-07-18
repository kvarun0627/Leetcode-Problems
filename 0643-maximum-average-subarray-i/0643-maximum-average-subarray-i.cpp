class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=-1e9;
        double sum=0;
        int n=nums.size();
        int l=0;
        for(int r=0;r<n;r++)
        {
            sum+=nums[r];
            if(r-l+1>k)
            {
                sum-=nums[l];
                l++;
            }
            if(r-l+1==k)
            {
                ans=max(ans,sum/k);
            }
        }
        return ans;
    }
};