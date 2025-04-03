class Solution {
public:
    bool can(vector<int>& dist, double hour, int mid)
    {
        double h=0;
        int n=dist.size();
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            {
                h+=(double)dist[i]/mid;
            }
            else
            {
                h+=ceil((double)dist[i] / mid);
            }
        }
        return h<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int high=1e7;
        int low=1;
        int ans=-1;
        while(high>=low)
        {
            int mid=(high+low)/2;
            if(can(dist,hour,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};