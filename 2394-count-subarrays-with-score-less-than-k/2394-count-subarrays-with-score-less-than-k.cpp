class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long total=0;
        int n=nums.size();
        int j=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
            while(j<=i && total*(i-j+1)>=k)
            {
                total-=nums[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};