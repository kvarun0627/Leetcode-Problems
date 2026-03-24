class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
        int n = nums.size();
        stack<int>st;
        vector<int>nse(n,n);
        vector<int>psee(n,-1);
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
               st.pop(); 
            }
            if(!st.empty())
            {
                nse[i] = st.top();
            }
            st.push(i);
        }

        stack<int>st1;
        for(int i=0;i<n;i++)
        {
            while(!st1.empty() && nums[st1.top()] > nums[i])
            {
                st1.pop();
            }
            if(!st1.empty())
            {
                psee[i] = st1.top();
            }
            st1.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int l = psee[i];
            int r = nse[i];
            l++;
            r--;
            if(k>=l && k<=r)
            {
                ans = max(ans , nums[i] * (r-l+1));
            }
        }

        return ans;
    }
};