class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) 
    {
        int n=nums.size();
        vector<long long>pref(n+1,0);

        for(int i=0;i<n;i++)
        {
            pref[i+1] = pref[i] + nums[i];
        }

        vector<int>NSE(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()] > nums[i])
            {
                NSE[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int>PSEE(n,-1);
        stack<int>st1;
        for(int i=n-1 ;i>=0 ;i--)
        {
            while(!st1.empty() && nums[st1.top()] >= nums[i])
            {
                PSEE[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }

        long long maxi = 0;
        for(int i=0;i<n;i++)
        {
            int L = PSEE[i] + 1;
            int R = NSE[i] - 1;
            maxi = max(maxi , 1LL * nums[i] * (pref[R+1]-pref[L]));
        }
        int mod  = 1e9+7;
        return maxi%mod;
    }
};