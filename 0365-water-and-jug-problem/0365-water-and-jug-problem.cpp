class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        queue<pair<int,int>>q;
        set<pair<int,int>>st;
        q.push({0,0});
        st.insert({0,0});
        int cap1=x;
        int cap2=y;
        while(!q.empty())
        {
            auto [jug1,jug2]=q.front();
            q.pop();
            if(jug1==target || jug2==target || jug1+jug2==target)
            {
                return true;
            }
            //fill1
            if(!st.count({cap1,jug2}))
            {
                cout<<cap1<<" "<<jug2<<endl;
                q.push({cap1,jug2});
                st.insert({cap1,jug2});
            }
            //fill2
            if(!st.count({jug1,cap2}))
            {
                cout<<jug1<<" "<<cap2<<endl;
                q.push({jug1,cap2});
                st.insert({jug1,cap2});
            }
            //empty1
            if(!st.count({0,jug2}))
            {
                cout<<0<<" "<<jug2<<endl;
                q.push({0,jug2});
                st.insert({0,jug2});
            }
            //empty2
            if(!st.count({jug1,0}))
            {
                cout<<jug1<<" "<<0<<endl;
                q.push({jug1,0});
                st.insert({jug1,0});
            }
            //transfer to 1
            int transfer_1=min(cap1-jug1,jug2);
            if(!st.count({jug1+transfer_1,jug2-transfer_1}))
            {
                cout<<jug1+transfer_1<<" "<<jug2-transfer_1<<endl;
                q.push({jug1+transfer_1,jug2-transfer_1});
                st.insert({jug1+transfer_1,jug2-transfer_1});
            }
            //transfer to 2
            int transfer_2=min(cap2-jug2,jug1);
            if(!st.count({jug1-transfer_2,jug2+transfer_2}))
            {
                cout<<jug1-transfer_2<<" "<<jug2+transfer_2<<endl;
                q.push({jug1-transfer_2,jug2+transfer_2});
                st.insert({jug1-transfer_2,jug2+transfer_2});
            }
        }
        return false;
    }
};