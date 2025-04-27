class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0;
        int j=2;
        int n=nums.size();
        int ans=0;
        while(j<n)
        {
            if(nums[i+1]%2==0 && nums[i]+nums[j]==nums[i+1]/2)
            {
                ans++;
            }
            j++;
            i++;
            
        }
        return ans;
    }
};