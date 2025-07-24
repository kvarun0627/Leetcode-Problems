class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>suff(n,1);
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1]*nums[i+1];
        }
        int pref=nums[0];
        for(int i=1;i<n;i++)
        {
            suff[i]=suff[i]*pref;
            pref=pref*nums[i];
        }
        return suff;
    }
};