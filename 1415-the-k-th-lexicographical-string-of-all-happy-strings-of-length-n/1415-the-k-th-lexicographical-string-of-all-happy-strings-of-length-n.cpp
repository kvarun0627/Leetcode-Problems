class Solution {
public:
    int m=0;
    string ans;
    void back_track(int n,int k,vector<char>&abc,int len,string s)
    {
        if(len==n)
        {
            m++;
            if(m==k)
            {
                ans=s;
            }
            return ;
        }
        for(char x:abc)
        {
            if(s.empty() || s.back()!=x)
            {
                back_track(n,k,abc,len+1,s+x);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<char>abc={'a','b','c'};
        back_track(n,k,abc,0,"");
        return ans;
    }
};