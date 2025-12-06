class Solution {
public:
    int reverse(int n)
    {
        int m=0;
        while(n)
        {
            m=m*10+n%10;
            n=n/10;
        }
        return m;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            int y=reverse(x);
            if(mp.find(x)!=mp.end())
            {
                ans=min(ans,i-mp[x]);
            }
            mp[y]=i;
        }
        return ans==n ? -1:ans;
    }
};