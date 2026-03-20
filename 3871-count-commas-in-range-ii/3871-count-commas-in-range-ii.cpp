class Solution {
public:
    long long countCommas(long long n) 
    {
        long long prev = 1;
        long long commas = 0;
        long long ans = 0;
        while(prev*1000 <= n)
        {
            long long next = prev*1000;
            ans += commas*(next-prev);
            prev = next;
            commas++;
        }
        ans += commas*(n-prev+1);
        return ans;
    }
};