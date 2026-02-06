class Solution {
public:
    int memo(int idx1,int idx2,vector<int>& nums, int k,int n)
    {
        if(nums[idx1]*k>=nums[idx2])
        {
            cout<<n-1-idx2+idx1;
            return n-idx2+idx1+1;
        }
        int ans=INT_MAX;
        ans=min(ans,memo(idx1+1,idx2,nums,k,n));
        ans=min(ans,memo(idx1,idx2-1,nums,k,n));
        ans=min(ans,memo(idx1+1,idx2-1,nums,k,n));
        return ans;
    }
    int BS(vector<int>&nums,int k,int n,long long val)
    {
        int low=0;
        int high=n-1;
        while(low<=high)
            {
                int mid=(low+high)/2;
                if((long long)nums[mid]>val)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
        return high;
    }
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // int i=0;
        int n=nums.size();
        // int cnt1=0;
        // while(i<n)
        //     {
        //         if(nums[i]*k>=nums[n-1])
        //         {
        //             break;
        //         }
        //         cnt1++;
        //         i++;
        //     }
        // i=n-1;
        // int cnt2=0;
        // while(i>=0)
        //     {
        //         if(nums[0]*k>=nums[i])
        //         {
        //             break;
        //         }
        //         cnt2++;
        //         i--;
        //     }
        // return min(cnt1,cnt2);
        int ans=INT_MAX;
        for(int idx1=0;idx1<n;idx1++)
            {
                int idx2=BS(nums,k,n,(long long)nums[idx1]*k);
                cout<<idx2<<" ";
                ans=min(ans,n-1-idx2+idx1);
            }
        return ans;
    }
};