class Solution {
public:
    int memo(int index,string&s,int sum,int n,bool tight,vector<vector<unordered_map<int,int>>>&DP)
    {
        if(index==n)
        {
            return sum;
        }
        if(DP[index][tight].find(sum)!=DP[index][tight].end())
        {
            return DP[index][tight][sum];
        }
        int ans=0;
        if(tight)
        {
            for(int num=0;num<=s[index]-'0';num++)
            {
                ans+=memo(index+1,s,sum+(num==1),n,num==s[index]-'0',DP);
            }
            return DP[index][tight][sum]=ans;
        }
        for(int num=0;num<=9;num++)
        {
            ans+=memo(index+1,s,sum+(num==1),n,0,DP);
        }
        return DP[index][tight][sum]=ans;
    }
    int countDigitOne(int n) {
        string s="";
        while(n)
        {
            s+=((n%10)+'0');
            n/=10;
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        int m=s.size();
        vector<vector<unordered_map<int,int>>>DP(m,vector<unordered_map<int,int>>(2));
        return memo(0,s,0,m,1,DP);
    }
};