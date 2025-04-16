class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,long long>mp;
        long long pairs=0;
        long long ans=0;
        int left=0;
        long long n=nums.size();
        for(long long right=0;right<n;right++)
        {
            pairs+=mp[nums[right]];
            mp[nums[right]]++;
            while(pairs>=k)
            {
                ans+=n-right;
                mp[nums[left]]--;
                pairs-=mp[nums[left]];
                left++;
            }
        }
        return ans;
    }
};