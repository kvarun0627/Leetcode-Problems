class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        int len=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                len=0;
            }
            else
            {
                len++;
                ans+=len;
            }
        }
        return ans;
    }
};