class Solution {
public:
    int nth_smallest(int val,int m,int n)
    {
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            cnt+=min(val/i,n);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nth_smallest(mid,m,n)>=k)
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};