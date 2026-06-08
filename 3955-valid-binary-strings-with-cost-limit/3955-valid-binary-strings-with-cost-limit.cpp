class Solution {
public:
    void reccur(string str , int idx , int n , int k , vector<string>&ans , bool flag)
    {
        if(idx >= n)
        {
            if(k >= 0)
            {
                ans.push_back(str);
            }
            return ;
        }

        if(flag)
        {
            reccur(str + '1' , idx+1, n , k-idx ,ans , false);
        }
        reccur(str + '0' , idx + 1 , n , k , ans , true);
    }

    vector<string>getAns(int n,int k)
    {
        vector<string>ans;
        reccur("",0,n,k,ans,true);
        return ans;
    }

    vector<string> generateValidStrings(int n, int k) 
    {
        return getAns(n,k);
    }
};