class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        int mod=1e9+7;
        priority_queue<pair<int,int>>Maxi;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Mini;
        vector<int>DP(n+1,0);
        vector<int>pref(n+1,0);
        DP[0]=1;
        pref[0]=1;
        int l=0;

        for(int r=0;r<n;r++)
        {
            Maxi.push({nums[r],r});
            Mini.push({nums[r],r});

            int mx,mn;
            while(Maxi.top().second<l)
            {
                Maxi.pop();
            }
            while(Mini.top().second<l)
            {
                Mini.pop();
            }
            mx=Maxi.top().first;
            mn=Mini.top().first;

            while(mx-mn>k)
            {
                l++;
                while(Maxi.top().second<l)
                {
                    Maxi.pop();
                }
                while(Mini.top().second<l)
                {
                    Mini.pop();
                }
                mx=Maxi.top().first;
                mn=Mini.top().first;
            }
            if(l>0)
            {
                DP[r+1]=(pref[r]-pref[l-1]+mod)%mod;
            }
            else
            {
                DP[r+1]=pref[r]%mod;
            }
            pref[r+1]=(pref[r]+DP[r+1])%mod;
        }

        return DP[n];
    }
};