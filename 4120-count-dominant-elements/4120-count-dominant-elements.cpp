class Solution {
public:
    int countDominantElements(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
        {
            return 1;
        }

        int ans = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(i==0 && nums[i] >= nums[i+1])
            {
                ans++;
            }
            else if(i == n-1 && nums[i] >= nums[i-1])
            {
                ans++;
            }
            else if(i>0 && i<n-1 && 2*nums[i] >= nums[i-1]+nums[i+1])
            {
                ans++;
            }
        }
        return ans;
    }
};