class Solution {
public:
    int reccur(int left,int right,vector<int>&arr,vector<vector<int>>&DP)
    {
        if(left+1==right)
        {
            return 0;
        }
        if(DP[left][right]!=-1)
        {
            return DP[left][right];
        }
        int ans=0;
        for(int i=left+1;i<right;i++)
        {
            int points=arr[i]*arr[left]*arr[right];
            points+=(reccur(left,i,arr,DP)+reccur(i,right,arr,DP));
            ans=max(ans,points);
        }
        return DP[left][right]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n+2);
        arr[0]=arr[n+1]=1;
        for(int i=1;i<=n;i++)
        {
            arr[i]=nums[i-1];
        }
        vector<vector<int>>DP(n+2,vector<int>(n+2,-1));
        
        return reccur(0,n+1,arr,DP);
    }
};