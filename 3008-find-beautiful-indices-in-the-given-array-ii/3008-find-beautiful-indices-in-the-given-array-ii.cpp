class Solution {
public:
    vector<int>Kmp(string s)
    {
        int n=s.size();
        vector<int>LPS(n,0);
        for(int i=1;i<n;i++)
        {
            int prev_idx=LPS[i-1];
            while(prev_idx>0 && s[i]!=s[prev_idx])
            {
                prev_idx=LPS[prev_idx-1];
            }
            LPS[i]=prev_idx+(s[i]==s[prev_idx]);
        }
        return LPS;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string A=a+" "+s;
        string B=b+" "+s;
        vector<int>va=Kmp(A);
        vector<int>vb=Kmp(B);
        vector<int>k1;
        vector<int>k2;

        for(int i=a.size()+1;i<A.size();i++)
        {
            if(va[i]==a.size())
            {
                k1.push_back(i-2*a.size());
            }
        }
        for(int i=b.size()+1;i<B.size();i++)
        {
            if(vb[i]==b.size())
            {
                k2.push_back(i-2*b.size());
            }
        }          
        vector<int>ans;
        for(int i = 0, j = 0; i < k1.size(); ++i)
        {
        while(j < k2.size() && k1[i] > k2[j] && abs(k1[i] - k2[j]) > k) j++;
        if(j < k2.size() && abs(k1[i] - k2[j]) <= k) ans.push_back(k1[i]);
        }
        return ans;
    }
};