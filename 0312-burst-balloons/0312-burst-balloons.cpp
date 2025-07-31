class Solution {
public:
    int memo(int left,int right,vector<int> &arr,vector<vector<int>> &DP)
    {
        if(DP[left][right]!=-1)
        {
            return DP[left][right];
        }
        int ans=0;
        for(int idx=left+1;idx<right;idx++)
        {
            int partition=arr[idx]*arr[left]*arr[right]+memo(idx,right,arr,DP)+memo(left,idx,arr,DP);
            ans=max(ans,partition);
        }
        return DP[left][right]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n+2,1);
        for(int i=0;i<n;i++)
        {
            arr[i+1]=nums[i];
        }

        vector<vector<int>>DP(n+2,vector<int>(n+2,-1));
        // for(int left=0;left<n+2;left++)
        // {
        //     for(int right=n+1;right>=0;right--)
        //     {
        //         int ans=0;
        //         for(int idx=left+1;idx<right;idx++)
        //         {
        //             int partition=arr[idx]*arr[left]*arr[right]+DP[idx][right]+DP[left][idx];
        //             ans=max(ans,partition);
        //         }
        //         DP[left][right]=ans;
        //     }
        // }
        return memo(0,n+1,arr,DP);
        return DP[0][n+1];
    }
};