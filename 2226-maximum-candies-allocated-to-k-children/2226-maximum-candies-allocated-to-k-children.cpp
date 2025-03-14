class Solution {
public:
    bool check(vector<int>& candies, long long k,int x)
    {
        long long n=0;
        for(int pile:candies)
        {
            n+=(pile/x);
        }
        return n>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int maxi=0;
        for(int x:candies)
        {
            maxi=max(maxi,x);
        }
        int low=1;
        int high=maxi;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(candies,k,mid))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high;
    }
};