class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        int rsum=0;
        int n=cardPoints.size();
        for(int i=0;i<=k-1;i++)
        {
            lsum+=cardPoints[i];
        }
        int ridx=n-1;
        int maxSum=lsum;
        for(int i=k-1;i>=0;i--)
        {
            rsum+=cardPoints[ridx--];
            lsum-=cardPoints[i];
            maxSum=max(maxSum,rsum+lsum);
        }
        return maxSum;
    }
};