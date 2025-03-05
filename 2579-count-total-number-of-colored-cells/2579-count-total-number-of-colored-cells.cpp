class Solution {
public:
    long long coloredCells(int n) {
        long long m=n-1;
        long long k=2*n-1;
        return 2*m*m+k;

    }
};