class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        long long ans=0;
        int f=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=technique1.size();
        for(int i=0;i<n;i++)
        {
            if(technique1[i]>=technique2[i])
            {
                ans+=technique1[i];
                f++;
            }
            else
            {
                ans+=technique2[i];
                pq.push(technique2[i]-technique1[i]);
            }
        }
        while(k>f)
        {
            ans-=pq.top();
            pq.pop();
            f++;
        }
        return ans;

    }
};