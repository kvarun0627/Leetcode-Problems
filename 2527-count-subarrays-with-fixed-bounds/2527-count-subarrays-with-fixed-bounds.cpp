class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long ans=0;
        int max_idx=-1;
        int min_idx=-1;
        int start_idx=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<minK || nums[i]>maxK)
            {
                start_idx=i+1;
            }
            if(minK==nums[i])
            {
                min_idx=i;
            }
            if(maxK==nums[i])
            {
                max_idx=i;
            }

            ans+=max(0,(min(min_idx,max_idx)-start_idx+1));
        }
        return ans;
    }
};