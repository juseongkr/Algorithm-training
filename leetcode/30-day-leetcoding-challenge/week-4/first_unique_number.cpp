class FirstUnique {
public:
	queue<int> que;
	unordered_map<int, int> mp;
	FirstUnique(vector<int>& nums) {
		for (const auto i : nums)
			mp[i]++;
		for (const auto i : nums)
			if (mp[i] == 1)
				que.push(i);
	}

	int showFirstUnique() {
		while (!que.empty() && mp[que.front()] != 1)
			que.pop();

		if (!que.empty())
			return que.front();
		return -1;
	}

	void add(int value) {
		if (++mp[value] == 1)
			que.push(value);
	}
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
