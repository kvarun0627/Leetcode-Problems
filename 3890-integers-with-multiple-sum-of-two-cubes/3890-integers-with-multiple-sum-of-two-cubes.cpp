class Solution {
public:
    vector<int> findGoodIntegers(int n) 
    {
        map<int,int>freq;
        vector<int>arr;
        for(int b = 1 ; b*b*b <= n ; b++)
        {
            for(int x : arr)
            {
                if(b*b*b > n-x)
                {
                    break;
                }
                freq[b*b*b + x]++;
            }
            arr.push_back(b*b*b);
        }

        vector<int>ans;
        for(auto& [num,cnt] : freq)
        {
            if(cnt > 1)
            {
                ans.push_back(num);
            }
        }

        return ans;
    }
};