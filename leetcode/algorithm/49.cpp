class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> mp;
		vector<vector<string>> ans;

		for (int i=0; i<strs.size(); ++i) {
			string p = strs[i];
			sort(p.begin(), p.end());
			mp[p].push_back(strs[i]);
		}

		auto it = mp.begin();
		while (it != mp.end()) {
			ans.push_back(it->second);
			it++;
		}

		return ans;
	}
};

