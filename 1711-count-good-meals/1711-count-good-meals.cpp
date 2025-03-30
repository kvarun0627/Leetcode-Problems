class Solution {
public:
    const int mod=1000000007;
    int two_sum(vector<int>&deliciousness,int target)
    {
        unordered_map<long long,long long>mp;
        int ans=0;
        for(auto x:deliciousness)
        {
            if(mp.find(target-x)!=mp.end())
            {
                ans=(ans+mp[(long long)(target-x)])%mod;
            }
            mp[(long long)x]++;
        }
        return ans%mod;
    }
    int countPairs(vector<int>& deliciousness) {
        int high=21;
        int ans=0;
        for(int low=0;low<=high;low++)
        {
            int target=1<<low;
            ans+=two_sum(deliciousness,target);
        }
        return ans;
    }
};