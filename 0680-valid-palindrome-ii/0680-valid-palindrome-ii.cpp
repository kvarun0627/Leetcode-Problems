class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                int a1=i+1;
                int b1=j;
                bool flag=false;
                while(a1<=b1)
                {
                    if(s[a1]!=s[b1])
                    {
                        flag=true;
                        break;
                    }
                    a1++;
                    b1--;
                }

                if(!flag) return true;

                int a2=i;
                int b2=j-1;
                while(a2<=b2)
                {
                    if(s[a2]!=s[b2])
                    {
                        return false;
                    }
                    a2++;
                    b2--;
                }

                return true;
            }
        }
        return true;
    }
};