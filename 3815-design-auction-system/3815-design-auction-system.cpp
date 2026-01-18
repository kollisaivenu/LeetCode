class AuctionSystem {
public:
    unordered_map<int, unordered_map<int, int>>lastBid;
    unordered_map<int, map<int, map<int, bool>>>bid;
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(lastBid[itemId][userId] == 0) {
            bid[itemId][bidAmount][userId] = true;
            lastBid[itemId][userId] = bidAmount;
        } else {
            updateBid(userId, itemId, bidAmount);
        }
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int lb = lastBid[itemId][userId];
        bid[itemId][lb].erase(userId);
        bid[itemId][newAmount][userId] = true;
        lastBid[itemId][userId] = newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        int lb = lastBid[itemId][userId];
        bid[itemId][lb].erase(userId);
        lastBid[itemId][userId] = 0;
    }
    
    int getHighestBidder(int itemId) {

        for(auto itr = bid[itemId].rbegin(); itr!=bid[itemId].rend();++itr) {
            if(!(itr->second).empty()) {
                return (itr->second).rbegin()->first;
            }
        }

        return -1;
        
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