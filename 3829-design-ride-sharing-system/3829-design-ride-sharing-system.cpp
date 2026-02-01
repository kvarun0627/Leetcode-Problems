class RideSharingSystem {
public:
    queue<int>rider,driver;
    set<int>exist,cancel;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) 
    {
        exist.insert(riderId);
        rider.push(riderId);
    }
    
    void addDriver(int driverId) 
    {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() 
    {
        int riderId=-1;
        int driverId=-1;
        while(!rider.empty() && cancel.count(rider.front()))
        {
            rider.pop();
        }

        if(!rider.empty())
        {
            riderId = rider.front();
        }
        
        if(!driver.empty())
        {
            driverId = driver.front();
        }

        if(riderId==-1 || driverId==-1)
        {
            return {-1,-1};
        }

        if(!rider.empty())
        {
            rider.pop();
        }
        if(!driver.empty())
        {
            driver.pop();
        }

        exist.erase(riderId);
        return {driverId,riderId};
    }
    
    void cancelRider(int riderId) 
    {
        if(exist.count(riderId))
        {
            cancel.insert(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */