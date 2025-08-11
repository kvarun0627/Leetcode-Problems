class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int n=nums.size();
        long long score=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            score+=nums[i];
            while(score*(i-j+1)>=k)
            {
                score-=nums[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};