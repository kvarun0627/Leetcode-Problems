class Solution {
public:
    long long aPowb(long long a , long long b)
    {
        long long ans = 1;
        while(b > 0)
        {
            if(b & 1)
            {
                ans = ans * a;
            }
            a = a*a;
            b = b/2;
        }
        return ans;
    }

    int countKthRoots(long long l, long long r, long long k) 
    {
        if(k==1)
        {
            return (r-l+1);
        }   

        long long num = 0;
        int cnt = 0;
        while(true)
        {
            long long xK = aPowb(num,k);

            if(xK > r)
            {
                break;
            }

            if(xK >= l && xK <= r)
            {
                cnt++;
                cout<< num <<" ";
            }
            num++;
        }

        return cnt;
    }
};