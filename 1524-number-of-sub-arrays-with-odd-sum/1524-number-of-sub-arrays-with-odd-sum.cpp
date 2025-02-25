class Solution {
public:
    long long mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int odd=0;
        int even=0;
        int curr_sum=0;
        long long cnt=0;
        for(int i:arr)
        {
            curr_sum+=i;
            if(curr_sum & 1)
            {
                cnt+=even+1;
                odd++;
            }
            else
            {
                cnt+=odd;
                even++;
            }
        }
        return cnt%mod;
    }
};