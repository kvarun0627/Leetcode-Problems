class Solution {
public:
    long long minCost(vector<int>& nums) 
    {
        long long ans = LLONG_MAX;
        int n = nums.size();
        int i = 1;
        while(i < n - 1)
        {
            int x = nums[i];
            int idx = i;
            while(i < n && nums[i] == x)
            {
                i++;
            }
            long long left = 0;
            if(nums[idx] == nums[idx-1])
            {
                left = 1LL*(idx-1)*x;
            }
            else
            {
                left = 1LL*idx*x;
            }
            long long score = left + 1LL*(n-i)*x;
            ans = min(ans , score);
        }    
        return ans;
    }
};