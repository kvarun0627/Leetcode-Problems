class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int top=INT_MAX;
        int bottom=INT_MAX;
        for(int val=1;val<=6;val++)
        {
            int swap1=0;
            int swap2=0;
            for(int j=0;j<n;j++)
            {
                if(tops[j]!=val && bottoms[j]==val) swap1++;
                else if(bottoms[j]!=val && tops[j]==val) swap2++;
                else if(tops[j]!=val && bottoms[j]!=val)
                {
                    swap1=INT_MAX;
                    swap2=INT_MAX;
                    break;
                }
            }
            top=min(top,swap1);
            bottom=min(bottom,swap2);
        }
        int ans=min(top,bottom);
        return ans==INT_MAX?-1:ans;
    }
};