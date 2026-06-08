class Solution {
public:
    int sumOfGoodIntegers(int n, int k) 
    {
        //for x <= n , n-x <= k --> x >= n-k
        //for x > n , n-x >= k --> x <= n-k

        int mid = n-k;
        int sum = 0;
        for(int x = max(0,n-k) ; x <= n+k ; x++)
        {
            if((x & n) == 0)
            {
                sum += x;
            }
        }

        return sum;
    }
};