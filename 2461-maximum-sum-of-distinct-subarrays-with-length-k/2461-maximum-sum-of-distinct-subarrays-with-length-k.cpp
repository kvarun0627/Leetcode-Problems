class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        int l=0;
        int n=nums.size();
        unordered_set<int>st;
        long long ans=0;
        for(int r=0;r<n;r++)
        {
            sum+=nums[r];
            while(st.count(nums[r]))
            {
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            st.insert(nums[r]);
            if(r-l+1>k)
            {
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            if(r-l+1==k)
            {
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};