class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            set<int>st1;
            set<int>st2;
            for(int j=i;j<n;j++)
            {
                if(nums[j]&1)
                {
                    st2.insert(nums[j]);
                }
                else
                {
                    st1.insert(nums[j]);
                }
                if(st1.size()==st2.size())
                {
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};