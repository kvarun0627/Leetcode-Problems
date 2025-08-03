class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words)  
    {
        int n=words.size();
        set<string>st(words.begin(),words.end());
        vector<string>ans;
        for(string word:words)
        {
            int m=word.size();
            vector<bool>DP(m+1,false);
            st.erase(word);
            DP[m]=true;
            for(int i=m-1;i>=0;i--)
            {
                string s="";
                for(int j=i;j<m;j++)
                {
                    s+=word[j];
                    DP[i]=DP[i] || (st.count(s) && DP[j+1]);
                }
            }
            if(DP[0])//DP[0] says is it possible to form the string by concatenation.
            {
                ans.push_back(word);
            }
            st.insert(word);
        }
        return ans;
    }
};