class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>DP(n,vector<int>(2,1));

        //intuition from 0/1 hole kadane DP
        //here DP[i][1] is defined as maximum length of the subarray ending at i where arr[i]<arr[i-1]
        // DP[i][0] is defined as maximum length of the subarray ending at i where arr[i-1]<arr[i]

        int maxi=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            {
                DP[i][0]=1+DP[i-1][1];
            }
            else if(arr[i-1]>arr[i])
            {
                DP[i][1]=1+DP[i-1][0];
            }
            maxi=max({maxi,DP[i][0],DP[i][1]});
        }
        return maxi;
    }
};