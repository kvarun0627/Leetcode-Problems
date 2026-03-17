class Solution {
public:
    long long gcdSum(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>prefixGcd;
        int mx = -1;
        for(int x:nums)
        {
            mx = max(mx,x);
            prefixGcd.push_back(__gcd(mx,x));
        }

        long long ans = 0;

        sort(prefixGcd.begin(),prefixGcd.end());
        int j = prefixGcd.size()-1;
        int i=0;
        while(i<j)
        {
            int x = __gcd(prefixGcd[i],prefixGcd[j]);
            ans += x;
            i++;
            j--;
        }

        return ans;
    }
};