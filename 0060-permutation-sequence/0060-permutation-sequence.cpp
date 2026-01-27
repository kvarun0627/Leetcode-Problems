class Solution {
public:
    string getPermutation(int n, int k) 
    {
        vector<int> fact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++)
        {
            fact[i] = fact[i - 1] * i;
        }

        set<int>st;
        for(int i=1;i<=n;i++)
        {
            st.insert(i);
        }

        auto it=st.begin();
        int pos=n;
        string ans="";
        while(pos>0)
        {
            int noOfWays=fact[pos-1];
            if(noOfWays<k)
            {
                k-=noOfWays;
                it++;
            }
            else
            {
                pos--;
                ans+=to_string(*it);
                st.erase(it);
                it=st.begin();
            }
        }

        return ans;
    }
};