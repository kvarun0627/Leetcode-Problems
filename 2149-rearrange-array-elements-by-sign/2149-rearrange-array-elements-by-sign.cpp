class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int even=0;
        int odd=1;
        for(int i:nums)
        {
            if(i>0)
            {
                ans[even]=i;
                even+=2;
            }
            else
            {
                ans[odd]=i;
                odd+=2;
            }
        }
        return ans;
    }
};