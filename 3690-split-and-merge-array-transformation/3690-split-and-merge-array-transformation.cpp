class Solution {
public:
    vector<string> next(string &s, int n)
    {
        vector<string> ans;
        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++) 
            {
                for (int k = 0; k < n; k++) 
                {
                    if (k < i) 
                    {
                        string str1 = s.substr(0, k);
                        string str2 = s.substr(k, i - k);
                        string str3 = s.substr(i, j - i + 1);
                        string str4 = s.substr(j + 1);
                        ans.push_back(str1 + str3 + str2 + str4);
                    } 
                    else if (k > j) 
                    {
                        string str1 = s.substr(0, i);
                        string str2 = s.substr(i, j - i + 1);
                        string str3 = s.substr(j + 1, k - j - 1);
                        string str4 = s.substr(k);
                        ans.push_back(str1 + str3 + str2 + str4);
                    }
                }
            }
        }

        return ans;
    }
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        string s1="";
        string s2="";
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            s1+=to_string(nums1[i]);
            s2+=to_string(nums2[i]);
        }

        unordered_map<string,int>mp;
        queue<string>q;
        q.push(s1);
        mp[s1]=0;
        while(!q.empty())
        {
            string a=q.front();
            q.pop();

            for(string&b:next(a,n))
            {
                if(mp.find(b)==mp.end())
                {
                    mp[b]=1+mp[a];
                    q.push(b);
                }
            }
        }
        return mp[s2];
    }
};