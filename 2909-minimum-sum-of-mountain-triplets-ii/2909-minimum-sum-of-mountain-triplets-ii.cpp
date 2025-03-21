class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>rightSmallest(n+1,INT_MAX);
        for(int i=n-1;i>=0;i--)
        {
            rightSmallest[i]=min(rightSmallest[i+1],nums[i]);
        }
        int leftSmallest=nums[0];
        int ans=INT_MAX;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>leftSmallest && nums[i]>rightSmallest[i+1])
            {
                ans=min(ans,leftSmallest+nums[i]+rightSmallest[i+1]);
            }
            leftSmallest=min(leftSmallest,nums[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};