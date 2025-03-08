class Twitter {
    public:
        int count;
        unordered_map<int, vector<vector<int>>> tweet_map;
        unordered_map<int, set<int>> follow_map;
    
        Twitter() {
            count = 0;
        }
        
        void postTweet(int userId, int tweetId) {
            tweet_map[userId].push_back({count++, tweetId});
            if(tweet_map[userId].size()>10){
                tweet_map[userId].erase(tweet_map[userId].begin());
            }
        }
        
        vector<int> getNewsFeed(int userId) {
            vector<int> ret;
            follow_map[userId].insert(userId);
    
            priority_queue<vector<int>> max_heap;
    
            for(auto& followeeId : follow_map[userId]){
                if(tweet_map.count(followeeId)){
                    const vector<vector<int>>& tweets = tweet_map[followeeId];
                    int index = tweets.size() - 1;
                    max_heap.push({tweets[index][0], tweets[index][1], followeeId, index});
                }
            }
            while(!max_heap.empty()&&ret.size()<10){
                vector<int> cur = max_heap.top();
                max_heap.pop();
                ret.push_back(cur[1]);
                int index = cur[3];
                if(index > 0){
                    const vector<int>& tweet = tweet_map[cur[2]][index-1];
                    max_heap.push({tweet[0], tweet[1], cur[2], index-1});
                }
            }
            return ret;
        }
        
        void follow(int followerId, int followeeId) {
            follow_map[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            if(follow_map.count(followerId) && follow_map[followerId].count(followeeId))
                follow_map[followerId].erase(followeeId);
        }
    };
    