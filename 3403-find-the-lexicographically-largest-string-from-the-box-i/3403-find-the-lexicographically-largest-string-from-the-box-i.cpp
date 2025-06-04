class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        char c='a';
        for(char ch:word)
        {
            if(c<ch)
            {
                c=ch;
            }
        }
        int n=word.size();
        string ans="a";
        for(int i=0;i<n;i++)
        {
            if(word[i]==c)
            {
                int allowed_len=min(n-i,n-numFriends+1);
                if(allowed_len<=0) continue;
                string s=word.substr(i,allowed_len);
                if(s>ans) ans=s;
            }
        }
        return ans;
    }
};