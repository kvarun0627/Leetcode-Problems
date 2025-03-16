class Solution {
public:
    bool check(vector<int>& ranks, int cars,int mid)
    {
        long long CARS=0;
        for(int i:ranks)
        {
            CARS+=(int)sqrt(mid/i);
        }
        return CARS>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int maxi=0;
        int mini=1;

        for(int i:ranks)
        {
            maxi=max(maxi,i);
        }

        long long high=maxi*cars*cars;
        long long low=1;
        long long ans;
        while(low<=high)
        {
            long long mid=(high-low)/2+low;
            if(check(ranks,cars,mid))
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