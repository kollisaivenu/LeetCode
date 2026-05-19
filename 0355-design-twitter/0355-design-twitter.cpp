class Twitter {
public:
    unordered_map<int, unordered_set<int>>followers;
    vector<pair<int, int>>posts;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>postlist;
        for(int i=posts.size()-1;i>=0;i--) {
            if(posts[i].first == userId || followers[userId].contains(posts[i].first)) {
                postlist.push_back(posts[i].second);
            }

            if(postlist.size() == 10) {
                break;
            }
        }

        return postlist;
        
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */