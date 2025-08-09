class Solution {
public:
    vector<int>coins;
    int size=0;
    int find(int amount,vector<vector<int>>&memo,int idx)
    {
        if(amount==0)
        {
            return 1;
        }
        if(amount<0 || idx==size)
        {
            return 0;
        }
        if(memo[amount][idx]!=-1)
        {
            return memo[amount][idx];
        }
        int ans=0;
        ans+=find(amount-coins[idx],memo,idx);
        ans+=find(amount,memo,idx+1);
        // cout<<endl;
        return memo[amount][idx]=ans;
    }
    vector<int> findCoins(vector<int>& numWays) {
        
        int N=numWays.size();
        for(int i=1;i<=N;i++)
        {
            vector<vector<int>>memo(i+1,vector<int>(size,-1));
            int ways=find(i,memo,0);
            // cout<<i<<" : "<<ways<<" , ";
            if(numWays[i-1]-1==ways)
            {
                // cout<<i<<" ";
                coins.push_back(i);
                size++;
            }
            else if(numWays[i-1]!=ways)
            {
                // cout<<"Got ended at "<<i<<endl;
                return {};
            }
        }
        return coins;
    }
};