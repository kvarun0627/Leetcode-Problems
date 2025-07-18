class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l=0;
        int n=arr.size();
        double sum=0;
        int ans=0;
        for(int r=0;r<n;r++)
        {
            sum+=arr[r];
            if(r>=k-1)
            {
                ans=ans+(sum/k>=threshold);
                sum-=arr[l++];
            }
        }
        return ans;
    }
};