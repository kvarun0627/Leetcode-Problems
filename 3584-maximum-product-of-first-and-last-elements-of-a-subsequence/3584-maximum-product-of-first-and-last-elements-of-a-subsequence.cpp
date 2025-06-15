class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        vector<long long>suff_min(n);
        vector<long long>suff_max(n);
        suff_min[n-1]=suff_max[n-1]=(long long)nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff_min[i]=min(suff_min[i+1],(long long)nums[i]);
            suff_max[i]=max(suff_max[i+1],(long long)nums[i]);
        }

        long long ans=LLONG_MIN;
        for(int i=0;i<n-m+1;i++)
        {
            if(nums[i]<0)
            {
                ans=max(ans,(long long)nums[i]*suff_min[i+m-1]);
            }
            else
            {
                ans=max(ans,(long long)nums[i]*suff_max[i+m-1]);
            }
        }
        return ans;
    }
};