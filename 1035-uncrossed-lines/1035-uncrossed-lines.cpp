class Solution {
public:
    int reccur(vector<vector<int>>&map ,vector<int>& nums1,int idx,int mini,vector<vector<int>>&DP)
    {
        if(idx==nums1.size()) return 0;

        if(DP[idx][mini+1]!=-1) return DP[idx][mini+1];

        int skip=reccur(map,nums1,idx+1,mini,DP);
        int not_skip=0;
        if(!map[nums1[idx]].empty())
        {
            for(int match:map[nums1[idx]])
            {
                if(match>=mini)
                {
                    not_skip=max(not_skip,1+reccur(map,nums1,idx+1,match+1,DP));
                }
            }
        }
        return DP[idx][mini+1]=max(skip,not_skip);

    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>map(2001);
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<m;i++)
        {
            map[nums2[i]].push_back(i);
        }
        vector<vector<int>>DP(n,vector<int>(m+2,-1));
        return reccur(map,nums1,0,-1,DP);
    }
};