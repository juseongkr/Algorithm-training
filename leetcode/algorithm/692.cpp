class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> m;
		for (const auto i : words)
			m[i]++;

		vector<pair<string, int>> vec;
		for (const auto i : m)
			vec.push_back(i);

		sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
			return a.second > b.second || (a.second == b.second && a.first < b.first);
		});

		vector<string> ret;
		for (const auto i : vec) {
			ret.push_back(i.first);
			if (--k == 0)
				break;
		}

		return ret;
	}
};
