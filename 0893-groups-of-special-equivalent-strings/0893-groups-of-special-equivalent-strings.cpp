class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<string>st;
        for(string s:words)
        {
            string even,odd;
            for(int i=0;i<s.size();i++)
            {
                if(i%2==0)
                {
                    even+=s[i];
                }
                else
                {
                    odd+=s[i];
                }
            }
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            st.insert(even+odd);
        }
        return st.size();
    }
};