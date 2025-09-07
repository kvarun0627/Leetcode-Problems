class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>nge(n,n+1);
        for(int i=0;i<n;i++)
            {
                while(!st.empty() && nums[st.top()]<=nums[i])
                {
                    nge[st.top()]=i;
                    st.pop();
                }
                if(st.empty() || nums[st.top()]>nums[i])
                {
                    st.push(i);
                }
            }
        stack<int>st2;
        vector<int>pge(n,-1);
        for(int i=n-1;i>=0;i--)
            {
                while(!st2.empty() && nums[st2.top()]<=nums[i])
                {
                    pge[st2.top()]=i;
                    st2.pop();
                }
                if(st2.empty() || nums[st2.top()]>nums[i])
                {
                    st2.push(i);
                }
            }
        long long ans=0;

        for(int i=0;i<n;i++)
            {
                if(nge[i]!=n+1 && nge[i]-i+1>=3)
                {
                    ans++;
                }
            }
        for(int i=n-1;i>=0;i--)
            {
                if(pge[i]!=-1 && i-pge[i]+1>=3)
                {
                    ans++;
                }
            }

        return ans;
    }
};