class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        auto solve=[&](int goal)
        {
            int j=0;
            int cnt=0;
            int ans=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i] & 1)
                {
                    cnt++;
                }
                while(cnt>goal)
                {
                    if(nums[j] & 1)
                    {
                        cnt--;
                    }
                    j++;
                }
                ans+=(i-j+1);
            }
            return ans;
        };
        return solve(k)-solve(k-1);
    }
};