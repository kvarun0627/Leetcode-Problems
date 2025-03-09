class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i=0;
        int j=1;
        int n=colors.size();
        int ans=0;
        while(i<n)
        {
            if(colors[j%n]!=colors[(j-1)%n])
            {
                if(j-i+1==k)
                {
                    i++;
                    ans++;
                }
                j++;
            }
            else
            {
                i=j;
                j++;
            }
        }
        return ans;
    }
};