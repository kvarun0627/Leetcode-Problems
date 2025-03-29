class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        unordered_map<double,long long>mp;
        for(int r=4;r<n-2;r++)
        {
            int q=r-2;
            for(int p=0;p<=q-2;p++)
            {
                mp[(double)nums[p]/(double)nums[q]]++;
            }
            for(int s=r+2;s<n;s++)
            {
                ans+=mp[(double)nums[s]/(double)nums[r]];
            }
        }
        return ans;
    }
};