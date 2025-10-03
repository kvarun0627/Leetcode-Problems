class Solution {
public:
    int memo(int index,int n,string&num,bool tight,bool frontZero,vector<string>&digits,int m,vector<vector<vector<int>>>&DP)
    {
        if(index==n)
        {
            return 1;
        }
        if(DP[index][tight][frontZero]!=-1)
        {
            return DP[index][tight][frontZero];
        }
        int ans=0;
        if(frontZero)
        {
            ans=memo(index+1,n,num,false,true,digits,m,DP);
        }
        if(tight)
        {

            for(int i=0;i<m && digits[i][0]<=num[index]; i++)
            {
                ans+=memo(index+1,n,num,digits[i][0]==num[index],false,digits,m,DP);
            }
            return DP[index][tight][frontZero]=ans;
        }
        for(int i=0;i<m;i++)
        {
            ans+=memo(index+1,n,num,false,false,digits,m,DP);
        }
        return DP[index][tight][frontZero]=ans;
    }
    int atMostNGivenDigitSet(vector<string>&digits, int n) {
        string num="";
        while(n)
        {
            num+=(n%10+'0');
            n/=10;
        }
        
        reverse(num.begin(),num.end());
        cout<<num<<endl;
        int m=num.size();
        vector<vector<vector<int>>>DP(m,vector<vector<int>>(2,vector<int>(2,-1)));
        return memo(0,m,num,true,true,digits,digits.size(),DP)-1;
    }
};