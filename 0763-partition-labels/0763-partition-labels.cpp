class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastoccurence(26,0);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            lastoccurence[s[i]-'a']=i;
        }
        vector<int>ans;
        int partitionstart=0;
        int partitionend=0;
        for(int i=0;i<n;i++)
        {
            partitionend=max(partitionend,lastoccurence[s[i]-'a']);
            if(i==partitionend)
            {
                ans.push_back(partitionend-partitionstart+1);
                partitionstart=i+1;
            }
        }
        return ans;
    }
};