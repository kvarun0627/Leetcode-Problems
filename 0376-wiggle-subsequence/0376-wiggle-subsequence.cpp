class Solution {
public:
    int reccur(int idx,int prev,int pos,vector<int>&nums,vector<vector<vector<int>>>&DP)
    {
        if(idx<0)
        {
            if(prev==-1) return 0;
            return 1;
        }

        if(DP[idx][prev+1][pos+1]!=-1) return DP[idx][prev+1][pos+1];

        int skip=reccur(idx-1,prev,pos,nums,DP);

        int take=0;

        if(prev==-1)
        {
            take=1+reccur(idx-1,idx,pos,nums,DP);
            return DP[idx][prev+1][pos+1]=max(take,skip);
        }

        if(nums[idx]==nums[prev]) return DP[idx][prev+1][pos+1]=skip;

        if(pos==-1)
        {
            if(nums[idx]-nums[prev]>0)
            {
                take=1+reccur(idx-1,idx,1,nums,DP);
            }
            else
            {
                take=1+reccur(idx-1,idx,0,nums,DP);
            }
            return DP[idx][prev+1][pos+1]=max(take,skip);
        }

        if(pos && nums[idx]<nums[prev])
        {
            take=1+reccur(idx-1,idx,0,nums,DP);
        }
        else if(!pos && nums[idx]>nums[prev])
        {
            take=1+reccur(idx-1,idx,1,nums,DP);
        }

        return DP[idx][prev+1][pos+1]=max(skip,take);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>>DP(n,vector<vector<int>>(n+1,vector<int>(3,-1)));
        return reccur(n-1,-1,-1,nums,DP)-1;
    }
};