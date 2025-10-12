class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        vector<int>arr(101,0);
        for(int num:nums)
        {
            arr[num]++;
        }
        int ans=0;
        for(int i=0;i<101;i++)
        {
            if(arr[i]==0)continue;

            if(arr[i]%k==0)
            {
                ans+=i*arr[i];
            }
        }
        return ans;
    }
};