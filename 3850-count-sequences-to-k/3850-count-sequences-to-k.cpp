class Solution {
public:

    vector<vector<int>>fact;
    int DP[20][101][64][50];

    int memo(int idx,int e2,int e3,int e5,vector<int>&expK,int n)
    {
        if(idx==n)
        {
            if(e2==expK[0] && e3==expK[1] && e5==expK[2])
            {
                return 1;
            }
            return 0;
        }

        if(DP[idx][e2+50][e3+32][e5+22]!=-1)
        {
            return DP[idx][e2+50][e3+32][e5+22];
        }

        int ans=memo(idx+1,e2,e3,e5,expK,n);

        int ne2 = e2 + fact[idx][0];
        int ne3 = e3 + fact[idx][1];
        int ne5 = e5 + fact[idx][2];
        ans+=memo(idx+1,ne2,ne3,ne5,expK,n);

        ne2 = e2 - fact[idx][0];
        ne3 = e3 - fact[idx][1];
        ne5 = e5 - fact[idx][2];
        ans+=memo(idx+1,ne2,ne3,ne5,expK,n);

        return DP[idx][e2+50][e3+32][e5+22] = ans;
    }
    int countSequences(vector<int>& nums, long long k) 
    {

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int>expK(3,0);
        while(k%5==0)
        {
            expK[2]++;
            k/=5;
        }
        while(k%3==0)
        {
            expK[1]++;
            k/=3;
        }
        while(k%2==0)
        {
            expK[0]++;
            k/=2;
        }

        if(k!=1)
        {
            return 0;
        }

        int n=nums.size();

        fact.assign(n , vector<int>(3,0));
        for(int i=0;i<n;i++)
        {
            int num = nums[i];
            while(num % 2 == 0) 
            {
                fact[i][0]++;
                num /= 2;
            }
            while(num % 3 == 0) 
            {
                fact[i][1]++;
                num /= 3;
            }
            while(num % 5 == 0) 
            {
                fact[i][2]++;
                num /= 5;
            }
        }

        memset(DP, -1, sizeof(DP));
        return memo(0,0,0,0,expK,n);
    }
};