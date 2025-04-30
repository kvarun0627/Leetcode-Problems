class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i:nums)
        {
            int digits=log10(i)+1;
            if(!(digits&1))
            {
                ans++;
            }
        }
        return ans;
    }
};