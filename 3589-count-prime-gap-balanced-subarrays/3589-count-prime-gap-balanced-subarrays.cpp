class Solution {
public:
    typedef pair<int,int> pa;
    vector<bool>prime;
    void sieve(int maxi)
    {
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=maxi;i++)
        {
            if(prime[i])
            {
                for(int p=i*i;p<=maxi;p+=i)
                {
                    prime[p]=false;
                }
            }
        }
    }
    int primeSubarray(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        prime.assign(maxi+1,true);
        sieve(maxi);
        int n=nums.size();        
        // vector<int>pref(n+1,0);
        // for(int i=1;i<=n;i++)
        // {
        //     pref[i]=pref[i-1]+prime[nums[i-1]];
        // }
        vector<int>idx;
        priority_queue<pa>Maxi;
        priority_queue<pa,vector<pa>,greater<pa>>Mini;
        int prev_idx=-1;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++)
        {
            if(prime[nums[r]])
            {
                Maxi.push({nums[r],r});
                Mini.push({nums[r],r});

                while(Maxi.top().second<l)
                {
                    Maxi.pop();
                }
                while(Mini.top().second<l)
                {
                    Mini.pop();
                }

                int mx=Maxi.top().first;
                int mn=Mini.top().first;
                while(mx-mn>k)
                {
                    l++;
                    while(Maxi.top().second<l)
                    {
                        Maxi.pop();
                    }
                    while(Mini.top().second<l)
                    {
                        Mini.pop();
                    }

                    mx=Maxi.top().first;
                    mn=Mini.top().first;
                }
                idx.push_back(r);
            }
            int m=idx.size();
            if(m>=2 && idx[m-2]>=l)
            {
                ans+=(idx[m-2]-l+1);
            }
        }
        return ans;
    }
};