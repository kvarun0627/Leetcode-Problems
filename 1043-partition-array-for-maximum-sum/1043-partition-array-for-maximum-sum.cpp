class Solution {
public:
    // int memo(int prev,vector<int>&arr,int k,vector<int>&DP,int n)
    // {
    //     if(DP[prev+1]!=-1)
    //     {
    //         return DP[prev+1];
    //     }
    //     int maxi=0;
    //     int ans=0;
    //     for(int idx=prev+1;idx<=min(n-1,prev+k);idx++)
    //     {
    //         maxi=max(maxi,arr[idx]);
    //         ans=max(ans,(idx-prev)*maxi+memo(idx,arr,k,DP,n));
    //     }
    //     return DP[prev+1]=ans;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>DP(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int maxi=0;
            for(int j=i-1;j>=max(0,i-k);j--)
            {
                maxi=max(maxi,arr[j]);
                DP[i]=max(DP[i],(i-j)*maxi+DP[j]);
            }
        }
        return DP[n];
    }
};