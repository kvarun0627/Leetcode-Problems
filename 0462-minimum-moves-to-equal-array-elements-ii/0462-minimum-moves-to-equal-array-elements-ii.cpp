class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prefix=0;
        int suffix=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            suffix+=nums[i];
        }
        long long ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            suffix-=nums[i];
            ans=min(ans,(long long)(suffix-prefix-(long long)(n-1-2*i)*nums[i]));
            prefix+=nums[i];
        }
        return ans;
    }
};