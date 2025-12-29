#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree< pair<double,int>, null_type, less<pair<double,int>>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
class MedianFinder {
public:
    int uid;
    ordered_multiset om;
    MedianFinder() 
    {
        uid=0;
    }
    
    void addNum(int num) 
    {
        om.insert({(double)num,uid++});
    }
    
    double findMedian() 
    {
        int n=om.size();
        if(n & 1)
        {
            auto it=om.find_by_order(n/2);
            return it->first;
        }
        auto it1=om.find_by_order(n/2);
        auto it2=om.find_by_order((n-1)/2);
        double a=it1->first;
        double b=it2->first;
        return (a+b)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */