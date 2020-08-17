class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ans;
		unordered_map<string, int> mp;
		if (s.length() < 10)
			return ans;

		for (int i=0; i<=s.length()-10; ++i) {
			string p = s.substr(i, 10);
			mp[p]++;
		}

		for (const auto m : mp)
			if (m.second > 1)
				ans.push_back(m.first);

		return ans;
	}
};
