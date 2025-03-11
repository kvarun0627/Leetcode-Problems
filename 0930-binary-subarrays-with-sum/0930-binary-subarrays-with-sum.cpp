class Solution {
public:
    int subarrays_with_sum_atmost_goal(vector<int>& nums, int goal,int n)
    {
        int sum=0;
        int j=0;
        int i=0;
        int ans=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>goal && i<=j)
            {
                sum-=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        return subarrays_with_sum_atmost_goal(nums,goal,n)-subarrays_with_sum_atmost_goal(nums,goal-1,n);
    }
};