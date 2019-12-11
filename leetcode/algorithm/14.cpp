class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size())
			return "";

		string ans = "";
		int len = strs[0].length();
		for (int j=0; j<len; ++j) {
			char c = strs[0][j];
			for (int i=1; i<strs.size(); ++i) {
				if (strs[i][j] != c)
					return ans;
			}
			ans += c;
		}
		return ans;
	}
};
