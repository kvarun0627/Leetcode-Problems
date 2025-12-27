class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        stack<int>st;
        vector<int>PGE(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && weight[st.top()]<=weight[i])
            {
                st.pop();
            }

            PGE[i]=(!st.empty())?st.top():-1;
            st.push(i);
        }

        int last_shipped=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(PGE[i]>last_shipped)
            {
                ans++;
                last_shipped=i;
            }
        }
        return ans;
    }
};