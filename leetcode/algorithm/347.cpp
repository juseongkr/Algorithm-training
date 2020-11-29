class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		priority_queue<pair<int, int>> que;
		map<int, int> dict;

		for (const auto n : nums)
			dict[n]++;

		for (const auto d : dict)
			que.push({d.second, d.first});

		vector<int> ans;
		while (k--) {
			ans.push_back(que.top().second);
			que.pop();
		}

		return ans;
	}
};
