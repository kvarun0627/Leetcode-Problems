class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string s=countAndSay(n-1);
        int k=s.size();
        string ans="";
        for(int i=0;i<k;)
        {
            int count=0;
            char ele=s[i];
            while(i<k && s[i]==ele)
            {
                count++;
                i++;
            }
            ans+=(to_string(count)+ele);
        }
        return ans;
    }
};