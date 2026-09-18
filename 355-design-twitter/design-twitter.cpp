
class Twitter {
    struct Tweet {
        int id;
        int time;

        Tweet(int i, int t) {
            id = i;
            time = t;
        }
    };

    int time;

    // userId -> tweets posted by that user
    unordered_map<int, vector<Tweet>> tweets;

    // userId -> users they follow
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, time));
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<Tweet> allTweets;

        // Add user's own tweets
        for (Tweet tweet : tweets[userId]) {
            allTweets.push_back(tweet);
        }

        // Add tweets of followed users
        for (int followee : following[userId]) {
            for (Tweet tweet : tweets[followee]) {
                allTweets.push_back(tweet);
            }
        }

        // Newest tweets first
        sort(allTweets.begin(), allTweets.end(),
             [](Tweet a, Tweet b) {
                 return a.time > b.time;
             });

        // Return at most 10 tweets
        vector<int> result;

        for (int i = 0; i < allTweets.size() && i < 10; i++) {
            result.push_back(allTweets[i].id);
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

