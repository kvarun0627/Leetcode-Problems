class Solution {
public:
    double check(double mid, vector<vector<int>>& squares) 
    {
        double A=0.0;
        for (auto&sq:squares) 
        {
            double y=sq[1];
            double l=sq[2];
            if(mid>=y+l)
            {
                A+=l*l;
            } 
            else if(mid>y && mid<y+l)
            {
                A+=(mid- y)*l;
            }
        }
        return A;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double mn=INT_MAX;
        double mx=INT_MIN;
        double total_area=0.0;
        for (auto& sq:squares) 
        {
            double y = sq[1];
            double l = sq[2];
            mn = min(mn,y);
            mx = max(mx,y+l);
            total_area+=l*l;
        } 
        double low=mn;
        double high=mx;
        double max_error=1e-5;
        while (high-low>max_error)
        {
            double mid=(low+high)/2.0;
            double A1= check(mid, squares);
            if (A1<total_area/2.0)
            {
                low=mid;
            } 
            else
            {
                high=mid;
            }
        }
        return low;
    }
};