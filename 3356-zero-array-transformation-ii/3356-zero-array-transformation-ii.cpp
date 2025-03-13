class Solution {
public:
    bool can_transform(vector<int>& nums,vector<vector<int>>& queries,int k,int n)
    {
        vector<int>diff_array(n+1,0);
        for(int i=0;i<k;i++)
        {
            int start=queries[i][0];
            int end=queries[i][1];
            int val=queries[i][2];
            diff_array[start]+=val;
            diff_array[end+1]-=val;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=diff_array[i];
            if(sum<nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums,vector<vector<int>>& queries) {
        int n=nums.size();
        int l=0;
        int r=queries.size();
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(can_transform(nums,queries,mid,n))
            {
                r=mid-1;
                ans=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};