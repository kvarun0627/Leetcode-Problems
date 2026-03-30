class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums)
    {
        int i = -1;
        int j = 1e9;
        int n = nums.size();
        int ans = INT_MAX;
        for(int k=0 ; k<n ; k++)
        {
            if(nums[k] == 1)
            {
                i = k;
            }
            if(nums[k] == 2)
            {
                j = k;
            }
            if(i!=-1 && j!=1e9)
            {
                ans = min(ans, abs(i-j));
            }
        }

        if(ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};