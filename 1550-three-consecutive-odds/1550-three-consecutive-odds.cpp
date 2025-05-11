class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int sum=0;
        int r=0;
        int l=0;
        int n=arr.size();
        while(r<n)
        {
            sum+=arr[r]%2;
            if(r-l+1==3)
            {
                if(sum==3) return true;
                sum-=arr[l]%2;
                l++;
            }
            r++;
        }
        return false;
    }
};