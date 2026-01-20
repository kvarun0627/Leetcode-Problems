class AuctionSystem {
public:
    map<int,multiset<pair<int,int>>>mp1;
    map<int,map<int,int>>mp2;
    AuctionSystem()
    {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) 
    {
        int lastAmount=mp2[userId][itemId];
        mp2[userId][itemId]=bidAmount;
        if(lastAmount!=0)
        {
            mp1[itemId].erase(mp1[itemId].find({lastAmount,userId}));
        }
        mp1[itemId].insert({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) 
    {
        addBid(userId,itemId,newAmount);
    }
    
    void removeBid(int userId, int itemId) 
    {
        int bidAmount=mp2[userId][itemId];
        mp2[userId][itemId]=0;
        mp1[itemId].erase(mp1[itemId].find({bidAmount,userId}));
    }
    
    int getHighestBidder(int itemId) 
    {
        if(mp1[itemId].empty())
        {
            return -1;
        }
        auto pa=*mp1[itemId].rbegin();
        return pa.second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */