class Solution {
public:
    long long get_cnt(int m,vector<int>& order,int idx)
    {
        vector<bool>astrisk(m,false);
        for(int i=0;i<=idx;i++)
        {
            astrisk[order[i]]=true;
        }
        int prev_idx=-1;
        long long cnt=0;
        for(int i=m-1;i>=0;i--)
        {
            if(astrisk[i])
            {
                prev_idx=i;
                cnt+=m-prev_idx;
            }
            else
            {
                cnt+=(prev_idx==-1?0:((prev_idx==m-1)?1:m-prev_idx));
            } 
            // cout<<cnt<<" ";
        }
        // cout<<"| ";
        return cnt;
    }
    int minTime(string s, vector<int>& order, int k) {
        int m=s.size();
        // cout<<m<<endl;
        int low=0;
        int high=m-1;
        vector<string>states;
        // for(int i=0;i<m;i++)
        // {
        //     s[order[i]]='*';
        //     // cout<<s<<endl;
        //     states.push_back(s);
        // }
        int ans=-1;
        while(low<=high)
        { 
            int mid=(low+high)/2;
            // cout<<mid<<" | ";
            long long cnt=get_cnt(m,order,mid);
            // cout<<cnt<<" "<<endl;
            if(cnt>=(long long)k)
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};