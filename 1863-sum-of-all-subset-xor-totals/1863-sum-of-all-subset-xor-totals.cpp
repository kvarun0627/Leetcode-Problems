class Solution {
public:

    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int m=(1<<n)-1;
        int ans=0;
        for(int mask=0;mask<=m;mask++)
        {
            int sum=0;
            for(int i=0;i<n;i++)
            {
                if((1<<i) & mask)
                {
                    sum^=nums[i];
                }
            }
            ans+=sum;
        }
        return ans;
    }
};