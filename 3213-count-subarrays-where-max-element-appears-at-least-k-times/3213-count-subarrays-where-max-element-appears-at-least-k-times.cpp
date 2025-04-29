class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int j=0;
        int n=nums.size();
        int cnt=0;
        int ele=*max_element(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele)
            {
                cnt++;
            }
            while(cnt>=k)
            {
                if(nums[j]==ele)
                {
                    cnt--;
                }
                j++;
            }
            if(cnt==k-1)
            {
                ans+=j;
            }
        }
        return ans;
    }
};