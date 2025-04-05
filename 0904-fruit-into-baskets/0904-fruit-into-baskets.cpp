class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //approach 1 t.c=O(2n)
        // unordered_map<int,int>mp;
        // int n=fruits.size();
        // int l=0;
        // int r=0;
        // int ans=0;
        // while(r<n)
        // {
        //     mp[fruits[r]]++;
        //     while(mp.size()>2)
        //     {
        //         mp[fruits[l]]--;
        //         if(mp[fruits[l]]==0)
        //         {
        //             mp.erase(fruits[l]);
        //         }
        //         l++;
        //     }
        //     int window_length=r-l+1;
        //     ans=max(ans,window_length);
        //     r++;
        // }
        // return ans;

        //approach 2 t.c=O(n)
        unordered_map<int,int>mp;
        int n=fruits.size();
        int l=0;
        int r=0;
        int ans=0;
        while(r<n)
        {
            mp[fruits[r]]++;
            if(mp.size()>2)
            {
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)
                {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size()<=2)
            {
                int window_length=r-l+1;
                ans=max(ans,window_length);
            }
            r++;
        }
        return ans;
    }
};;