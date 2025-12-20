class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>>st(3);
        int n=nums.size();
        for(int i=0;i<n;i++)
            {
                st[nums[i]%3].push_back(nums[i]);
            }
        for(int i=0;i<3;i++)
            {
                sort(st[i].begin(),st[i].end(),greater<int>());
            }
        int ans=0;
        if(st[0].size()>=3)
        {
            ans=max(ans,st[0][0]+st[0][1]+st[0][2]);
        }
        if(st[1].size()>=3)
        {
            ans=max(ans,st[1][0]+st[1][1]+st[1][2]);
        }
        if(st[2].size()>=3)
        {
            ans=max(ans,st[2][0]+st[2][1]+st[2][2]);
        }
        if(!st[0].empty() && !st[1].empty() && !st[2].empty())
        {
            ans=max(ans,st[0][0]+st[1][0]+st[2][0]);
        }
        return ans;
    }
};