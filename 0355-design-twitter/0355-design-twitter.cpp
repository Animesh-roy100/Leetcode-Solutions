class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets; 
    unordered_map<int, unordered_set<int>> followers;
    int timeStamp;
    Twitter() {
        timeStamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto tweet: tweets[userId]) {
            pq.push(tweet);
        }
        
        for(auto follower: followers[userId]) {
            for(auto tweet: tweets[follower]) {
                pq.push(tweet);
            }
        }
        
        vector<int> ans;
        int maxTweets=10;
        while(!pq.empty() and maxTweets-->0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followers[followerId].insert(followeeId);   
        }
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