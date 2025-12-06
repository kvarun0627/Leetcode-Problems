class Solution {
public:
    int maxDistinct(string s) {
        vector<bool>vis(26,false);
        int ans=0;

        for(char c:s)
        {
            if(!vis[c-'a'])
            {
                ans++;
            }
            vis[c-'a']=true;
        }
        return ans;
    }
};