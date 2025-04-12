class Solution {
public:
    bool check(vector<int>& start,int d,int mid,int n)
    {
        int prev=start[0];
        for(int i=1;i<n;i++)
            {
                int curr=start[i];
                if(curr-prev>=mid)
                {
                    prev=curr;
                }
                else
                {
                    if(curr+d-prev<mid) return false;
                    curr=prev+mid;
                    prev=curr;
                }
            }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        int n=start.size();
        int maxi=start[n-1]+d-start[0];
        int low=1;
        int high=maxi;
        int ans=0;
        while(low<=high)
            {
                int mid=(high-low)/2+low;
                if(check(start,d,mid,n))
                {
                    ans=mid;
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        return ans;
    }
};