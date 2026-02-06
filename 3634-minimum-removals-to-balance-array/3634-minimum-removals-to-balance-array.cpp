class Solution {
public:
    int minRemoval(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            while((long long)nums[i]*k < (long long)nums[j])
            {
                i++;
            }
            ans = min(ans,n - (j-i+1));
        }  
        return ans;
    }
};