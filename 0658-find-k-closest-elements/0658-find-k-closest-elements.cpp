class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>pa;
        for(int y:arr)
        {
            pa.push_back({abs(y-x),y});
        }
        sort(pa.begin(),pa.end());
        vector<int>ans;
        for(int i=0;i<arr.size() && k>=1;i++)
        {
            ans.push_back(pa[i].second);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};