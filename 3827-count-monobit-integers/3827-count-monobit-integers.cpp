class Solution {
public:
    int countMonobit(int n) 
    {
        int ans = 1;
        ans += log2(n+1);
        return ans;
    }
};