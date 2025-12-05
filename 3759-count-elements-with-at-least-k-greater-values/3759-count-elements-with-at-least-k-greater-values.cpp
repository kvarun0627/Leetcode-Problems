class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int j=0;
        int ans=0;
        for(int i=0;i<n;)
        {
            int num=nums[i];
            while(j<n && nums[j]==num)
            {
                j++;
            }
            if(n-j>=k)
            {
                ans+=(j-i);
            }
            i=j;
        }
        return ans;
    }
};