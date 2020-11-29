class Twitter {
public:
	/** Initialize your data structure here. */
	unordered_map<int, unordered_map<int, int>> dict;
	unordered_map<int, unordered_set<int>> flw;
	int idx;

	Twitter(): idx(0) {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		dict[userId][tweetId] = ++idx;
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		unordered_set<int> st;

		st.insert(userId);
		for (auto f : flw[userId])
			st.insert(f);

		priority_queue<pair<int, int>> que;
		for (auto s : st)
			for (auto it : dict[s])
				que.push({it.second, it.first});

		int cnt = 10;
		vector<int> ret;
		while (!que.empty() && cnt--) {
			auto cur = que.top();
			que.pop();
			ret.push_back(cur.second);
		}

		return ret;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		flw[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (flw[followerId].count(followeeId))
			flw[followerId].erase(followeeId);
	}
};
