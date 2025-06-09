class Solution {
public:
    int palindrome(string &s,int left,int right,int n)
    {
        while(left>=0 && right<n && s[left]==s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int max_length=0;
        for(int i=0;i<n;i++)
        {
            int odd=palindrome(s,i,i,n);//for "abcba"
            int even=palindrome(s,i,i+1,n);// for "abba"

            int length=max(odd,even);
            if(max_length<length)
            {
                max_length=length;
                start=i-(max_length-1)/2;
            }
        }
        return s.substr(start,max_length);
    }
};